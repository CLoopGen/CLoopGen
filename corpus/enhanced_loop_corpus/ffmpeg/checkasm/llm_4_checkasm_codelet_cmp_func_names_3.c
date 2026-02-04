#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *a;
extern  char *b;
extern int ascii_diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *a && *b; a++, b++) {
        ascii_diff = *(const unsigned char *)a - *(const unsigned char *)b;
        if (ascii_diff) break;
    }
}
