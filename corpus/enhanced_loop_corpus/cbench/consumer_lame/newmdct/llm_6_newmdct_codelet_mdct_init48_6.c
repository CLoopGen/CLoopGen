#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FLOAT8 temp[36];
    for (i = 0; i < 36; i++)
        temp[i] = win[1][35 - i];
    for (i = 0; i < 36; i++)
        win[3][i] = temp[i];
}
