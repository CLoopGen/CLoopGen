#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *pattern;
extern int patternLen;
extern int backslashCount;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile int temp = 0;
    for (int i = patternLen - 2; i >= 0; i--) {
        if (pattern[i] == '\\' && temp % 2 == 0)
            ++backslashCount;
        else if (pattern[i] == '\\' && temp % 2 == 1)
            backslashCount--;
        if (pattern[i] != '\\') break;
        temp++;
    }
    if (temp % 2 == 1) {
        backslashCount++; 
    }
}
