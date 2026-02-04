#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 2; i++) {
    for (k = 0; k < 4; k++) {
        FLOAT8 a;
        int row = (i == 0) ? 0 : (i == 1 ? 1 : 3);
        if (row == 0 || row == 1 || row == 3) {
            a = win[row][17 - k];
            win[row][17 - k] = win[row][9 + k];
            win[row][9 + k] = a;
            a = win[row][35 - k];
            win[row][35 - k] = win[row][27 + k];
            win[row][27 + k] = a;
        }
    }
}
}
