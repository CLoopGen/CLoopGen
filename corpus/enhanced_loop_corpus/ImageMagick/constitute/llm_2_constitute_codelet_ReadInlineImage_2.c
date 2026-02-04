#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *content;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element)
    char *temp = content;
    while ((*temp != ',') && (*temp != '\x00')) {
        temp += 2; // Stride of 2
        if (*(temp - 1) == ',' || *(temp - 1) == '\x00') {
            p = temp - 1;
            return;
        }
    }
    p = temp;
}
