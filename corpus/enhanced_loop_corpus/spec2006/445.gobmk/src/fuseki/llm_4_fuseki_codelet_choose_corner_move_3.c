#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int i;
extern int q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        if (table[i] <= 0) {
            continue;
        }
        q -= table[i];
        if (q < 0)
            break;
    }
}
