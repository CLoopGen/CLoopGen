#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 255; i += 2) {
        table[i] = (JSAMPLE)i;
        if (i + 1 <= 255) {
            table[i + 1] = (JSAMPLE)(i + 1);
        }
    }
}
