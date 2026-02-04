#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT in[5][44][2];
extern INTFLOAT L[2][38][64];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reordering nested loops and using pointer arithmetic for stride-1 access
    INTFLOAT (*in_ptr)[2] = &in[0][6];
    for (j = 0; j < 38; j++) {
        for (i = 0; i < 5; i++) {
            in_ptr[j * 5 + i][0] = L[0][j][i];  // Now accessing in as consecutive blocks
            in_ptr[j * 5 + i][1] = L[1][j][i];
        }
    }
}
