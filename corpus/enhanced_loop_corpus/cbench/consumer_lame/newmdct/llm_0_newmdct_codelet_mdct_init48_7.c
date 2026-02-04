#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 4; k++) {
    for (int j = 0; j < 3; j++) {
        FLOAT8 a;
        if (j == 0) {
            a = win[0][17 - k];
            win[0][17 - k] = win[0][9 + k];
            win[0][9 + k] = a;
            a = win[0][35 - k];
            win[0][35 - k] = win[0][27 + k];
            win[0][27 + k] = a;
        } else if (j == 1) {
            a = win[1][17 - k];
            win[1][17 - k] = win[1][9 + k];
            win[1][9 + k] = a;
            a = win[1][35 - k];
            win[1][35 - k] = win[1][27 + k];
            win[1][27 + k] = a;
        } else if (j == 2) {
            a = win[3][17 - k];
            win[3][17 - k] = win[3][9 + k];
            win[3][9 + k] = a;
            a = win[3][35 - k];
            win[3][35 - k] = win[3][27 + k];
            win[3][27 + k] = a;
        }
    }
}
}
