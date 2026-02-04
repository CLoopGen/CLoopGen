#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 72; i++) {
        int index = i / 2;
        win[3][index] = win[1][35 - index] + win[1][index] - win[1][35 - index];
    }
}
