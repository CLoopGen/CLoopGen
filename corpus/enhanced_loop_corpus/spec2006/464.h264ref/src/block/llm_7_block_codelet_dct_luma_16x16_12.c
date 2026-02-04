#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int M4[4][4];
extern int M0[4][4][4][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        int row_sum = 0;
        for (j = 0; j < 4; j++) {
            row_sum += M0[0][i][0][j];
            M4[i][j] = row_sum; // Introduces RAW dependency and loop-carried dependence
        }
    }
}
