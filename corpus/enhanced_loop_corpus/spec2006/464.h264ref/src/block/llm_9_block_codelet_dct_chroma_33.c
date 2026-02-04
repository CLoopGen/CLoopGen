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
for (i = 0; i < 2 && !lossless_qpprime; i++) {
    for (j = 0; j < 4; j++) {
        j1 = 3 - j;
        int sum = m4[i][j] + m4[i][j1];
        int diff = m4[i][j] - m4[i][j1];
        m5[j] = sum;
        m5[j1] = diff;
        if (j == 0 || j == 1) {
            m4[i][j] = (m5[j] + m5[3-j]) >> 1;
            m4[i][3-j] = (m5[j] - m5[3-j]) >> 1;
        }
    }
}
}
