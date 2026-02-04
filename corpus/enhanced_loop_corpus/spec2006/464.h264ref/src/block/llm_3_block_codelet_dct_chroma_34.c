#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern int i;
extern int j;
extern int i1;
extern int m5[4];
extern int m6[4];
extern int m4[4][4];
extern Boolean lossless_qpprime;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Variant 1: Strided memory access pattern on m4 using pointer arithmetic with fixed stride
int *p_m4_col = &m4[0][0] + j; // Base pointer for column j, updated inside outer loop
for (j = 0; j < 4 && !lossless_qpprime; j++) {
    int *p_m4 = &m4[0][0] + j; // Start at column j, row 0
    for (i = 0; i < 4; i++, p_m4 += 4) { // Stride of 4 (column-major walk)
        m5[i] = *p_m4;
    }
    m6[0] = m5[0] + m5[2];
    m6[1] = m5[0] - m5[2];
    m6[2] = m5[1] - m5[3];
    m6[3] = m5[1] + m5[3];
    for (i = 0; i < 2; i++) {
        i1 = 3 - i;
        m4[i][j] = m6[i] + m6[i1];
        m4[i1][j] = m6[i] - m6[i1];
    }
}
}
