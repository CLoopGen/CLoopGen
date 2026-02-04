#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *pattern;
extern int patternLen;
extern int backslashCount;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = patternLen - 2; i >= 0 && pattern[i] != '\\'; i--) {
        break;
    }
    for (int i = patternLen - 2; i >= 0; i--) {
        if (pattern[i] == '\\') {
            backslashCount++;
        } else {
            break;
        }
    }
}
