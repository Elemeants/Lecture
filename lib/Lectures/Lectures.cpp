/**
    Object class: Lectures
    Documentation:
*/
#include "Lectures.h"

// @purpuse Get the number of elements in a char*
// @param  Text->char pointer to count
// @return Len->number of elements
int Length(char *Text)
{
	int Len = 0;
	while (Text[Len] != '\0')
		Len++;
	return Len;
}

// @purpuse Get the number of elements in a char*
// @param  Text->char pointer to count
// @return Len->number of elements
int Length(int _vr)
{
	int Len = 0;
	for (; _vr > 0; Len++)
		_vr /= 10;
	return Len;
}

char Convert::ToChar(int _val){
    if(_val >= 0 && _val < 10){
        const char Values[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        return Values[_val];
    }
    return '\0';
}

int Convert::ToInt(char _var)
{
	const char Values[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	for (int res = 0; res < 10; res++) {
		if (Values[res] == _var)
			return res;
	}
	return ERROR;
}

int Convert::ToInt(char *_line)
{
	int value = 0;
    int ptr = 0;
	for (int cnt = (Length(_line) - 1); cnt >= 0; cnt--) {
        int first = ToInt(_line[cnt]);
        float power = pow(10, ptr);
		value += (first * power);
        ptr ++;
	}
	return value;
}

int Read::readKeyInt()
{ return Convert::ToInt(getch()); }

int Read::readInt()
{ readInt(MAX_INT_LENGTH); }

int Read::readInt(int _maxLength)
{
    if(_maxLength > 0 && _maxLength <= MAX_INT_LENGTH){
        char Line[_maxLength];
        int Value = 0;
        for(int x = 0; x < _maxLength; x++){
            char Lectura = getch();
            int lec = Convert::ToInt(Lectura);
            if (Lectura == CHAR_ENTER) break;
            if (Lectura == CTRL_C)     return 0;
            if (lec     == ERROR)      x--;
            else{
                Lectura = Convert::ToChar(lec);
                printf("%c", Lectura);
                Line[x] = Lectura;
            }
        }
        return Convert::ToInt(Line);
    }
    else
        return ERROR;
}

char Read::readChar()
{ return readChar(WITH_DIGIT); }

char Read::readChar(bool _notDigit)
{
    const char Values[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char Lecture = '\0';
    bool isFine = true;
    while(isFine)
    {
        isFine = false;
        Lecture = getch();
        if (_notDigit)
        {
            for(int x = 0; x < 10; x++)
            {
                if(Lecture == Values[x])
                    isFine = true;
            }
        }
    }
    printf("%c", Lecture);
    return Lecture;
}

char* Read::readLine()
{ return readLine(WITH_DIGIT); }

char* Read::readLine(bool _digits)
{
    char *line = new char[STRING_BUFFER];
    char holder;
    int i = 0;
    while(i < STRING_BUFFER)
    {
        holder = getch();
        if (!isdigit(holder) || !_digits)
        {
            line[i] = holder;
            if(holder == CHAR_ENTER ||
               holder == CTRL_C)
            {
                printf("\n");
                break;
            }
            printf("%c", holder);
            i++;
        }
    }
    return line;
}
