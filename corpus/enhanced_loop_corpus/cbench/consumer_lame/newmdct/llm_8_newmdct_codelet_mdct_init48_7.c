#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 8; k += 2) {
    FLOAT8 a;
    int i = 17 - k;
    int j = 9 + k;
    a = win[0][i];
    win[0][i] = win[0][j];
    win[0][j] = a;
    a = win[0][35 - k];
    win[0][35 - k] = win[0][27 + k];
    win[0][27 + k] = a;

    a = win[1][i];
    win[1][i] = win[1][j];
    win[1][j] = a;
    a = win[1][35 - k];
    win[1][35 - k] = win[1][27 + k];
    win[1][27 + k] = a;

    if (k < 4) {
        a = win[3][i];
        win[3][i] = win[3][j];
        win[3][j] = a;
        a = win[3][35 - k];
        win[3][35 - k] = win[3][27 + k];
        win[3][27 + k] = a;
    }
}
}
