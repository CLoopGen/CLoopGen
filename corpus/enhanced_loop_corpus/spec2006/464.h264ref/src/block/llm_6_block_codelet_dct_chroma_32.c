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
    int temp_m5[4];
    for (i = 0; i < 2; i++) {
        i1 = 3 - i;
        temp_m5[i] = m4[i][j] + m4[i1][j];
        temp_m5[i1] = m4[i][j] - m4[i1][j];
    }
    m4[0][j] = temp_m5[0] + temp_m5[1];
    m4[2][j] = temp_m5[0] - temp_m5[1];
    m4[1][j] = temp_m5[3] + temp_m5[2];
    m4[3][j] = temp_m5[3] - temp_m5[2];
}
}
