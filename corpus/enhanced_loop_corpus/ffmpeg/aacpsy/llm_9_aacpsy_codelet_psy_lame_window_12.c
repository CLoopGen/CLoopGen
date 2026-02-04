#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int attacks[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 6 + 1; i++) {
        int temp1 = attacks[i];
        int temp2 = attacks[i - 1];
        if (temp1 > 0 && temp2 > 0) {
            attacks[i] = temp1 - (temp2 >> 1);
        }
    }
}
