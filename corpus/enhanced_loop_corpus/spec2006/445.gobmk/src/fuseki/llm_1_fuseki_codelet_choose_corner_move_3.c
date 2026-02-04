#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int i;
extern int q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8 && q >= 0; i++) {
        int temp_q = q;
        for (int k = 0; k < 1; k++) {
            q -= table[i];
            if (temp_q < 0)
                break;
        }
    }
}
