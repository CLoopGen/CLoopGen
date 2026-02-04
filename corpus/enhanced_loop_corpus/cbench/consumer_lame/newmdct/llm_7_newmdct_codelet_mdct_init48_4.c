#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 24; i += 2) {
        win[1][i] = 1.;
        if (i + 1 < 24) {
            win[1][i + 1] = 1.;
        }
    }
}
