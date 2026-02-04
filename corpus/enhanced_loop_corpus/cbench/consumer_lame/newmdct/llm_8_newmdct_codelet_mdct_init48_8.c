#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;
extern FLOAT8 max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 18; i++) {
    win[0][2*i] *= max / 32768;
    win[0][2*i + 1] *= max / 32768;
    win[1][2*i] *= max / 32768;
    win[1][2*i + 1] *= max / 32768;
    win[3][2*i] *= max / 32768;
    win[3][2*i + 1] *= max / 32768;
}
}
