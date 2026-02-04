#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (; i < 12; i++) {
        for (j = 0; j < 3; j++) {
            win[1][i * 2 + j] = 1.;
        }
    }
}
