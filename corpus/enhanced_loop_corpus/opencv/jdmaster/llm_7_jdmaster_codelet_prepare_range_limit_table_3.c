#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JSAMPLE *t = table;
    volatile int temp = 0;
    for (i = 128; i < 510; i += 2) {
        t[i] = 255;
        t[i+1] = 255;
        temp += i; // Introduce artificial WAW and loop-carried dependency via temp
    }
    if ((510 - 128) % 2 != 0 && i == 510)
        t[i-1] = 255;
}
