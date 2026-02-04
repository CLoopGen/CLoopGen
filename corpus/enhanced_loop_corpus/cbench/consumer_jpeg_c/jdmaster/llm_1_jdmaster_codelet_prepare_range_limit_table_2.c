#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 128; i < 2 * (255 + 1); i++) {
        for (int inner = 0; inner < 1; inner++) {
            table[i] = 255;
        }
    }
}
