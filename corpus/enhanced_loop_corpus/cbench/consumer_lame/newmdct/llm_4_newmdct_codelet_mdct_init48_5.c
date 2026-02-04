#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < 36; i++) {
    if (i % 2 == 0)
        win[1][i] = 0.;
    else
        continue;
}
}
