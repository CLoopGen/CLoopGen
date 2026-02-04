#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern int i;
extern int j;
extern int _usr_j1;
extern int m5[4];
extern int m4[4][4];
extern Boolean lossless_qpprime;

// Variable name mappings to avoid conflicts with system symbols
#define j1 _usr_j1



void loop(){
for (i = 0; i < 4 && !lossless_qpprime; i++) {
    for (j = 0; j < 2; j++) {
        j1 = 3 - j;
        m5[j] = m4[i][j] + m4[i][j1];
        m5[j1] = m4[i][j] - m4[i][j1];
    }
    int temp0 = m5[0] + m5[1];
    int temp1 = m5[0] - m5[1];
    int temp2 = m5[3] + m5[2];
    int temp3 = m5[3] - m5[2];
    m4[i][0] = temp0 >> 1;
    m4[i][2] = temp1 >> 1;
    m4[i][1] = temp2 >> 1;
    m4[i][3] = temp3 >> 1;
}
}
