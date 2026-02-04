#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;
extern FLOAT8 max;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 36; i++) {
    win[0][i] *= max / 32768;
    win[1][i] *= max / 32768;
    win[3][i] *= max / 32768;
}

}
