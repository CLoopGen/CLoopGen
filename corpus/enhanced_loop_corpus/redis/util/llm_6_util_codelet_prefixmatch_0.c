#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *pattern;
extern int patternLen;
extern int backslashCount;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int localBackslashCount = backslashCount;
    for (int i = patternLen - 2; i >= 0; i--) {
        localBackslashCount += (pattern[i] == '\\') ? 1 : 0;
        if (pattern[i] != '\\') break;
    }
    backslashCount = localBackslashCount;
}
