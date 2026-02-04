#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *pattern;
extern int patternLen;
extern int backslashCount;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = patternLen - 2;
    while (i >= 0 && pattern[i] == '\\') {
        ++backslashCount;
        --i;
    }
}
