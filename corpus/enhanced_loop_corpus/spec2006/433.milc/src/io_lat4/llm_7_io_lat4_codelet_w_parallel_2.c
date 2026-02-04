#include <stdio.h>

#include <inttypes.h>

typedef struct {
    double real;
    double imag;
} complex;

typedef struct {
    complex e[3][3];
} su3_matrix;

extern su3_matrix *lbuf;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Eliminate loop-carried dependencies entirely and increase parallelism
    // Reorder loops to make 'i' the innermost, allowing full independence across j and k
    // No data dependencies (RAW, WAR, WAW) are carried between outer loop iterations
    // All operations are independent and can be vectorized or parallelized aggressively

    for (j = 0; j < 3; j++) {
        for (k = 0; k < 3; k++) {
            for (i = 0; i < 4096; i++) {
                lbuf[i].e[j][k].real = 0.0;
                lbuf[i].e[j][k].imag = 0.0;
            }
        }
    }
}
