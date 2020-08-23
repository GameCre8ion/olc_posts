// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
// 
// cre8Binary.h
//
// Small utility header for helper functions like binary number visualization and 
// 32 bit endian swapping 
//  
// This code is released under MIT License and is part of the sample code for the blogs posted 
// at community.onelonecoder.com.
// 
// A big Thank You to David Barr, aka Javidx9, and his excellent One Lone Coder Community!
// https://community.onelonecoder.com/
// 
// Enjoy!
//
// Kevin Runge (GameCre8ion)
//
//
// The Legal Stuff:
// 
// MIT License
// Copyright (c) 2020 Gamecre8ion
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=


#include <iostream>
#include <cstdint>
#include <bitset>
#include <climits>


namespace cre8 {

	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	// Helper function and enum to detect endianness of machine
	// which runs the code.
	// C++ 2020 standard will offer better tools
	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	
	enum class Endian_t	{
		LITTLE = 0,
		BIG = 1,
	};

	Endian_t GetSystemEndianness( )	{
		const int32_t constval = 0x01;
		const void* addr = static_cast<const void *>( &constval );
		// get least significant address (lsa)
		const unsigned char* lsa = static_cast<const unsigned char *>(addr);
		
		if ( *lsa == 0x01 ) {
			return Endian_t::LITTLE;
		} 
		else {
			return Endian_t::BIG;
		}
	}

	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	// Endian Swap Functions based on the book
	// "Game Engine Architecture" 2nd Edition by Jason Gregory
	// Chapter 3 pg. 132
	// ISBN 978-1-4665-6001-7
	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	
	uint32_t EndianSwap( uint32_t value ) {		
		return 	(( value & 0x000000FF ) << 24 )
			|	(( value & 0x0000FF00 ) << 8 )
			|	(( value & 0x00FF0000 ) >> 8 )
			|	(( value & 0xFF000000 ) >> 24 );
	}

	float EndianSwapF32( float value ) {
		// The original code uses a union for type punning, 
		// however this is undefined behaviour in C++.
		// This function uses a reinterpret_cast, the 
		// disadvantage is that this function can lead to compiler 
		// optimization bugs when strict aliasing is enabled.
		uint32_t* intPtr = reinterpret_cast<uint32_t*>( &value );
		uint32_t temp = EndianSwap( *intPtr );
	
		return *reinterpret_cast<float*>( &temp );
	}
	
	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	// Print binary value representation
	// Function splits the binary number with a space at each CHAR_BIT interval
	// Idea based on a StackOverflow post:
	// https://stackoverflow.com/questions/7349689/how-to-print-using-cout-a-number-in-binary-form
	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

	template<typename T>
	void PrintBinaryRepr( const T& value ) { 
		const char* begin = reinterpret_cast<const char*>( &value );
    	const char* end = begin + sizeof( value );
    
		while( begin != end ) {
        	std::cout << std::bitset<CHAR_BIT>( *begin++ ) << ' ';
		}
    	std::cout << std::endl;
	}	

	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	// Helper functions for returning size of vars 
	// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	uint32_t CharSizeInBits( ) {
		return CHAR_BIT;
	}

	uint32_t CharSizeInBytes( ) {
		return (CHAR_BIT / 8);
	}	
}