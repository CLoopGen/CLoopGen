#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 36; i += 2) {
        win[3][i] = win[1][35 - i];
        if (i + 1 < 36)
            win[3][i + 1] = win[1][35 - (i + 1)];
    }
}
