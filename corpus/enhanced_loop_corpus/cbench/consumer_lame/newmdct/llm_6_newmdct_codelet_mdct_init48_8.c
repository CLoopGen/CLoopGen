#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;
extern FLOAT8 max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FLOAT8 temp0, temp1, temp3;
    for (i = 0; i < 36; i++) {
        temp0 = win[0][i] * max / 32768;
        temp1 = win[1][i] * max / 32768;
        temp3 = win[3][i] * max / 32768;
        win[0][i] = temp0;
        win[1][i] = temp1;
        win[3][i] = temp3;
    }
}
