/**
    Header class: Lectures
    Documentation: This library helps you to read and convert
                   values from the console.

    Autor:   Daniel Polanco - jdanypa@gmail.com
             https://github.com/Elemeants
    Version: 1.0
    Date:    2018/09/11
*/
#ifndef LECTURES_H
#define LECTURES_H
#pragma once
/// Libraries definitions
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/// MACROS
#define WITH_DIGIT     false
#define NO_DIGIT       true
#define MAX_INT_LENGTH 9
#define CHAR_ENTER     13
#define CTRL_C         3
#define ERROR          -1
#define STRING_BUFFER  100

/// Length functions
/// Allows you to get the size of a string
/// or the Length of a number int
int Length(char*);
int Length(int);

/// Struct convert, all the functions are static so
/// don't need to initialize
struct Convert{
    /// Conversion to INT from a char
    static int ToInt(char);
    /// Conversion to INT from a CHAR*
    static int ToInt(char*);
    /// Conversion from INT to CHAR
    static char ToChar(int);
    /// Conversion from INT to CHAR*
    static char* ToString(int);
};

struct Read{
    /// Read only a number
    static int readKeyInt();
    /// Read a number from the user
    static int readInt();
    /// Read a number with a max length
    static int readInt(int);
    /// Read any char
    static char readChar();
    /// Read a character not digit
    static char readChar(bool);
    /// Reads a line with whitespaces and digits
    static char* readLine();
    /// Reads a line without digits
    static char* readLine(bool);
};

#endif // !LECTURES_H
