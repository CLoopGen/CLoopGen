#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double out[3][3];
extern int i;
extern int j;
extern double det;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx;
    for (idx = 0; idx < 9; idx++) {
        int i = idx / 3;
        int j = idx % 3;
        out[i][j] *= det;
    }
}
