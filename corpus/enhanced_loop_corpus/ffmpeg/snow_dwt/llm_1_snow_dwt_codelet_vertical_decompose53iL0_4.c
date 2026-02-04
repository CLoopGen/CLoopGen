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
    int outer = width / 100 + 1;
    int chunk, start, end;
    for (i = 0; i < outer; i++) {
        start = i * 100;
        end = (start + 100 < width) ? start + 100 : width;
        if (start >= width) break;
        for (chunk = start; chunk < end; chunk++)
            b1[chunk] += (b0[chunk] + b2[chunk] + 2) >> 2;
    }
}
