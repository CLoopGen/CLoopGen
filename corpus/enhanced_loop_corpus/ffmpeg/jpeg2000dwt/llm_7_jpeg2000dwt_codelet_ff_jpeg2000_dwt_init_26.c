#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int border[2][2];
extern int i;
extern int j;
extern int b[2][2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i += 2) {
        for (j = 0; j < 4; j += 2) {
            int ii = i >> 1;
            int jj = j >> 1;
            if (ii < 2 && jj < 2) {
                b[ii][jj] = border[ii][jj];
            }
        }
    }
}
