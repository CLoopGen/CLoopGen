#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern using pointer arithmetic with fixed offsets
    for (k = 0; k < 4; k++) {
        FLOAT8 *base0 = win[0];
        FLOAT8 *base1 = win[1];
        FLOAT8 *base3 = win[3];
        int idx1 = 17 - k;
        int idx2 = 9 + k;
        int idx3 = 35 - k;
        int idx4 = 27 + k;
        FLOAT8 a;

        // Swap using strided access via computed indices
        a = base0[idx1];
        base0[idx1] = base0[idx2];
        base0[idx2] = a;

        a = base0[idx3];
        base0[idx3] = base0[idx4];
        base0[idx4] = a;

        a = base1[idx1];
        base1[idx1] = base1[idx2];
        base1[idx2] = a;

        a = base1[idx3];
        base1[idx3] = base1[idx4];
        base1[idx4] = a;

        a = base3[idx1];
        base3[idx1] = base3[idx2];
        base3[idx2] = a;

        a = base3[idx3];
        base3[idx3] = base3[idx4];
        base3[idx4] = a;
    }
}
