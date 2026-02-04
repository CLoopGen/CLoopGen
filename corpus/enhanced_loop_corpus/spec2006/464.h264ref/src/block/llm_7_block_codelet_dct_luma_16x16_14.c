#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern int i;
extern int j;
extern int _usr_j1;
extern int M4[4][4];
extern int M5[4];
extern Boolean lossless_qpprime;

// Variable name mappings to avoid conflicts with system symbols
#define j1 _usr_j1



void loop(){
    for (i = 0; i < 4 && !lossless_qpprime; i++) {
        int t0, t1, t2, t3;
        t0 = M4[i][0] + M4[i][3];
        t3 = M4[i][0] - M4[i][3];
        t1 = M4[i][1] + M4[i][2];
        t2 = M4[i][1] - M4[i][2];
        M4[i][0] = (t0 + t1) >> 1;
        M4[i][2] = (t0 - t1) >> 1;
        M4[i][1] = (t3 + t2) >> 1;
        M4[i][3] = (t3 - t2) >> 1;
    }
}
