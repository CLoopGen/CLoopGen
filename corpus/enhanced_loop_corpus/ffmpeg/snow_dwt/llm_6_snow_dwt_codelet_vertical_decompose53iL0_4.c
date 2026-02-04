#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

extern DWTELEM *b0;
extern DWTELEM *b1;
extern DWTELEM *b2;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    DWTELEM temp;
    for (i = 0; i < width; i++) {
        temp = (b0[i] + b2[i] + 2) >> 2;
        b1[i] += temp;
    }
}
