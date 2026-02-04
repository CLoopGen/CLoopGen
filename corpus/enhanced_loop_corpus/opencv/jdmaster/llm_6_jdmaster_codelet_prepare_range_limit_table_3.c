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
    for (i = 128; i < 510; i++) {
        t[i] = (JSAMPLE)(t[i-1] + 1); // Introduce RAW dependency: each write depends on prior read
    }
}
