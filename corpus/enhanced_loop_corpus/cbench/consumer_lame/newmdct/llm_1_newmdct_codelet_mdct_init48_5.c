#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (i < 36) {
    do {
        win[1][i] = 0.;
        i++;
    } while (i < 36);
}
}
