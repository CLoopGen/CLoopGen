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
        int temp_val0, temp_val1, temp_val2, temp_val3;
        temp_val0 = m4[i][0] + m4[i][3];
        temp_val3 = m4[i][0] - m4[i][3];
        temp_val1 = m4[i][1] + m4[i][2];
        temp_val2 = m4[i][1] - m4[i][2];
        m4[i][0] = (temp_val0 + temp_val1) >> 1;
        m4[i][2] = (temp_val0 - temp_val1) >> 1;
        m4[i][1] = (temp_val3 + temp_val2) >> 1;
        m4[i][3] = (temp_val3 - temp_val2) >> 1;
    }
}
