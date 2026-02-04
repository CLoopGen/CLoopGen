#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 win[4][36];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 4; k++) {
    FLOAT8 a;
    
    // Swap first pair unconditionally
    a = win[0][17 - k];
    win[0][17 - k] = win[0][9 + k];
    win[0][9 + k] = a;

    // Skip second operation if k is 0 or 3
    if (k == 1 || k == 2) {
        a = win[0][35 - k];
        win[0][35 - k] = win[0][27 + k];
        win[0][27 + k] = a;
    }

    // Perform third and fourth operations only when k is even
    if (k % 2 == 0) {
        a = win[1][17 - k];
        win[1][17 - k] = win[1][9 + k];
        win[1][9 + k] = a;
        a = win[1][35 - k];
        win[1][35 - k] = win[1][27 + k];
        win[1][27 + k] = a;
    }

    // Perform last two swaps every iteration but with conditional symmetry
    a = win[3][17 - k];
    win[3][17 - k] = win[3][9 + k];
    win[3][9 + k] = a;

    if (k != 2) {  // Avoid one swap for variation in control flow
        a = win[3][35 - k];
        win[3][35 - k] = win[3][27 + k];
        win[3][27 + k] = a;
    }
}
}
