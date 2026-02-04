#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer <= 1; outer++) {
        for (i = 0; i <= 255; i++) {
            table[i] = (JSAMPLE)i;
        }
    }
}
