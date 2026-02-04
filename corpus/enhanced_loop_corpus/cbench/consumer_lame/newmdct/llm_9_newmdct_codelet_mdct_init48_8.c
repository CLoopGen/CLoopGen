#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;
extern FLOAT8 max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
FLOAT8 scale = max / 32768;
FLOAT8 scale_sq = scale * scale;
for (i = 0; i < 36; i++) {
    win[0][i] = (win[0][i] * scale) + (win[0][i] * scale_sq);
    win[1][i] = (win[1][i] * scale) + (win[1][i] * scale_sq);
    win[3][i] = (win[3][i] * scale) + (win[3][i] * scale_sq);
}
}
