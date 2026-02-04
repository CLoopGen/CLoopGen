#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int i;
extern int q;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_q = q;
    for (i = 0; i < 8; ++i) {
        temp_q -= table[i];
        if (temp_q < 0)
            break;
    }
    q = temp_q;
}
