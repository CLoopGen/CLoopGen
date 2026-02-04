#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 9; i++) {
        win[1][2*i]     = win[0][2*i];
        win[1][2*i + 1] = win[0][2*i + 1] * 2.0;
    }
}
