// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
// 
// bit_magic_1.cpp
//  
// This code is released under MIT License and is part of the sample code for the blogs posted 
// at community.onelonecoder.com.
// 
// A big Thank You to David Barr, aka Javidx9, and his excellent One Lone Coder Community!
// https://onelonecoder.com/
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
#include "cre8_binary.hpp"


int main( int argc, char* argv[] ) { 

    // our testing floats
    // two famous mathematical constants
    float pi = 3.141592653589793f;
    float e = 2.718281828459046f;
    uint32_t answer = 42;
    float simple = 1.5f;

    std::cout << "=-=-=-= Bit Magic 1 =-=-=-= " << std::endl;
    std::cout << std::endl;

    std::cout << "Binary represenations:" << std::endl;
    
    std::cout << "Pi = ";
    cre8::PrintBinaryRepr( pi );
    std::cout << std::endl;
    
    std::cout << "e = ";
    cre8::PrintBinaryRepr( e );
    std::cout << std::endl;

    std::cout << "simple = ";
    cre8::PrintBinaryRepr( simple );
    std::cout << std::endl;

    std::cout << "answer = ";
    cre8::PrintBinaryRepr( answer );

    return 0;
}