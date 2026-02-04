#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FLOAT8 temp[24];
    for (int j = 0; j < 24; j++) {
        temp[j] = 1.;
        win[1][j] = temp[j];
    }
    i = 24;
}
