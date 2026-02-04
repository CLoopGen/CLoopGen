#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int i;
extern int q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    q -= table[0];
    for (i = 1; i < 4; i++) {
        q -= (table[i] + table[7 - i]) * 2;
        if (q < 0)
            break;
    }
}
