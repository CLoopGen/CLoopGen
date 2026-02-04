#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *message;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *src = message;
    size_t i = 0;
    while (src[i] != '\x00') i++;
    for (size_t j = 0; j < i; j++) {
        if (*(src + j) == '\n')
            *(src + j) = ' ';
    }
}
