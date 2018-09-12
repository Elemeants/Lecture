/**
    Project: Lecture
    File: main.cpp
    Autor: Jdany
    Version: 1.0
    Date: 2018/09/11
*/
#include "main.h"

int main(void)
{
    printf(" Ingrese una cadena: ");
    char* Lectura = Read::readLine(NO_DIGIT);
    printf(" Lectura -> %s", Lectura);
    return 0;
}
