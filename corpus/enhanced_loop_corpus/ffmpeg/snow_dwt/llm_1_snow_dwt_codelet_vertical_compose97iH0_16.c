#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b0;
extern IDWTELEM *b1;
extern IDWTELEM *b2;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = width / 100 + 1;
    int chunk_size = 100;
    int start, end;

    for (i = 0; i < outer; i++) {
        start = i * chunk_size;
        end = (start + chunk_size > width) ? width : start + chunk_size;
        for (int k = start; k < end; k++)
            b1[k] += (3 * (b0[k] + b2[k]) + 0) >> 1;
    }
}
