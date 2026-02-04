#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 255; i += 4) {
        table[i] = (JSAMPLE)i;
        if (i + 1 <= 255) table[i + 1] = (JSAMPLE)(i + 1);
        if (i + 2 <= 255) table[i + 2] = (JSAMPLE)(i + 2);
        if (i + 3 <= 255) table[i + 3] = (JSAMPLE)(i + 3);
    }
}
