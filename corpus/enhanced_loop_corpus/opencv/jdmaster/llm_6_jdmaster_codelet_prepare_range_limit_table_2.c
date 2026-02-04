#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPLE temp[256];
    for (i = 0; i <= 255; i++) {
        temp[i] = (JSAMPLE)i;
    }
    for (i = 0; i <= 255; i++) {
        table[i] = temp[i];
    }
}
