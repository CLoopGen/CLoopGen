#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int i;
extern int q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_q = q;
    for (i = 0; i < 16; i += 2) {
        temp_q -= table[i];
        if (i + 1 < 16) {
            temp_q -= table[i + 1];
        }
        if (temp_q < 0)
            break;
    }
    q = temp_q;
}
