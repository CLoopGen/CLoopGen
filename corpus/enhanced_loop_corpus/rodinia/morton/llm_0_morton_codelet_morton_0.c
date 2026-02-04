#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int *x;
extern int *y;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (b = 0; b < 4; b++) {
        for (int inner = 0; inner < 4; inner++) {
            int idx = b * 4 + inner;
            *x |= (i & (1 << (idx * 2))) >> idx;
            *y |= (i & (1 << (idx * 2 + 1))) >> (idx + 1);
        }
    }
}
