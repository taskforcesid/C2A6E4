//
// Aladin Sidahmed U08614258 
// aladin.sidahmed@gmail.com
// C/C++ Programming II 
// Section 145010 Ray Mitchell 
// 24 FEB 2020
// C2A6E4_OpenFile.c
// Operating System: Windows 7 
// Visual Studio Community 2019 Version 16.3.2 
//
// Implements OpenFile: opens a file and returns a pointer
// to the opened file. Terminates the program on failure
//

#include <stdio.h>
#include <stdlib.h>

FILE *OpenFile(const char *fileName)
{
    // OpenFile attempts to open filename. Returns a pointer
    // to the opened file, or terminates the program with EXIT_FAILURE
    // code
    FILE *filePtr;
    if ((filePtr = fopen(fileName, "r")) == NULL)
    {
        fprintf(stderr, "Failed to open file: %s\n", fileName);
        exit(EXIT_FAILURE);
    }
    return filePtr;
}
