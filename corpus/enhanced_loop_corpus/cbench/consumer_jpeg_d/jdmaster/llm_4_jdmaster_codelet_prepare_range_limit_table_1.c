#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 255; i++) {
        if (i % 2 == 0) {
            table[i] = (JSAMPLE)i;
        } else {
            continue;
        }
    }
}
