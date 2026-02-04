#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int sad;
extern int m2[8][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access - iterate over columns first with stride in rows
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j += 2) {
            sad += (((m2[j][i]) < (0) ? (-(m2[j][i])) : (m2[j][i])));
            if (j + 1 < 8)
                sad += (((m2[j+1][i]) < (0) ? (-(m2[j+1][i])) : (m2[j+1][i])));
        }
}
