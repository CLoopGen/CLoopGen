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
extern int m4[4][4];
extern Boolean lossless_qpprime;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4 && !lossless_qpprime; j++) {
    for (i = 0; i < 2; i++) {
        i1 = 3 - i;
        m5[i] = m4[i][j] + m4[i1][j];
        m5[i1] = m4[i][j] - m4[i1][j];
    }
    // Increase arithmetic intensity by adding extra computations
    int temp1 = m5[0] + m5[1];
    int temp2 = m5[0] - m5[1];
    int temp3 = m5[3] + m5[2];
    int temp4 = m5[3] - m5[2];
    // Additional operations to increase computational load
    temp1 += (m5[1] << 1);
    temp2 -= (m5[0] >> 1);
    temp3 ^= m5[2];
    temp4 |= m5[3];
    m4[0][j] = temp1;
    m4[2][j] = temp2;
    m4[1][j] = temp3;
    m4[3][j] = temp4;
}
}
