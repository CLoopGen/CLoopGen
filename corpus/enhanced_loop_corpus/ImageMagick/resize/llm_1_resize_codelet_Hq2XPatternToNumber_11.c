#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *pattern;
extern ssize_t i;
extern unsigned int result;
extern unsigned int order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 7; i >= 0; i--) {
        for (ssize_t inner = 0; inner < 1; inner++) {
            result += order * (unsigned int)pattern[i];
            order *= 2;
        }
    }
}
