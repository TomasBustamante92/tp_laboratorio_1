/*
 * inputs.c
 *
 *  Created on: Sep 23, 2021
 *      Author: Tomas Sanchez de Bustamante
 */


#include "inputs.h"

static int myGets(char* string, int len)
{
	__fpurge(stdin);
	fgets(string, len, stdin);

	string[strlen(string)-1] = '\0';
	return 0;
}


static int esNumerica(char* string)
{
    int comeback = 1;
    int i = 0;

    if((string[0] == '-' || string[0] == '+') && string[1] != '\0')
    {
        i=1;
    }

    for( ; string[i] != '\0' ; i++)
    {
        if(string[i] < '0' || string[i] > '9')
        {
        	comeback = 0;
            break;
        }
    }

    return comeback;
}


/// @fn int getInt(int*)
/// @brief ask the user for a stirng, checks if its a number, if it is, it changes it to int.
///
/// @param pResultado it returns a number if enter correctly
/// @return it returns [0]in case user has enter the number correctly, otherwise it returns [-1]
static int getInt(int* pResult)
{
    int comeback = -1;
    char buffer[4096];

    if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica(buffer))
    {
        *pResult = atoi(buffer);
        comeback = 0;
    }

    return comeback;
}


int input_requestNumberInt(int* pResult, char* message, char* error, int min, int max)
{
    int comeback = -1;
    int buffer;
    int bufferAnswer;

    if(pResult != NULL && message != NULL && error != NULL && min <= max)
    {
        printf("%s",message);
        bufferAnswer = getInt(&buffer);

		while(bufferAnswer == -1 || buffer < min || buffer > max)
		{
			printf("%s", error);
			bufferAnswer = getInt(&buffer);
		}

		*pResult = buffer;
		comeback = 0;
    }

    return comeback;
}


static int esFloat(char* string)
{
    int comeback = 1;
    int i = 0;
    int dotsCounter = 0;

    if((string[0] == '-' || string[0] == '+') && string[1] != '\0')
    {
        i=1;
    }

    for( ; string[i] != '\0' ; i++)
    {
        if(string[i] < '0' || string[i] > '9')
        {
        	if(string[i] == '.')
        	{
        		dotsCounter++;

	        	if(dotsCounter > 1)
	        	{
	        		comeback = 0;
	                break;
	        	}
        	}
            else
            {
            	comeback = 0;
				break;
            }
        }
    }

    return comeback;
}


static int getFloat(float* pResult)
{
    int comeback = -1;
    char buffer[4096];

    if(myGets(buffer, sizeof(buffer)) == 0 && esFloat(buffer))
    {
        *pResult = atof(buffer);
        comeback = 0;
    }

    return comeback;
}


int input_requestNumberFloat(float* pResult, char* message, char* error, int min, int max)
{
    int comeback = -1;
    float buffer;
    int respuestaBuffer;

    if(pResult != NULL && message != NULL && error != NULL && min <= max)
    {
        printf("%s",message);
    	respuestaBuffer = getFloat(&buffer);

		while(respuestaBuffer == -1 || buffer < min || buffer > max)
		{
			printf("%s", error);
			respuestaBuffer = getFloat(&buffer);
		}

		*pResult = buffer;
		comeback = 0;
    }

    return comeback;
}


int input_requestString(char* string, char* message, char* errorMessage, int max)
{
	int comeback = -1;
	char buffer[256];
	int len;

	if(string != NULL && message != NULL && errorMessage != NULL && max > 0)
	{
		printf("%s", message);
		__fpurge(stdin);
		scanf("%[^\n]", buffer);
		len = strlen(buffer);

		while(len > max)
		{
			printf("%s", errorMessage);
			__fpurge(stdin);
			scanf("%[^\n]", buffer);
			len = strlen(buffer);
		}

		strcpy(string, buffer);
		comeback = 0;
	}

	return comeback;
}
