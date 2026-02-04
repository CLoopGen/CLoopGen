#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_l = square + 11;
    for (l = square + 11; board[l] == 13; ) {
        m++;
        l += 11;
        if (l - prev_l != 11) break; // Introduce WAR-like anti-dependence on 'l'
        prev_l = l;
    }
}
