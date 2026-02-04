#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern int rem;
extern unsigned char *ovec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char temp1, temp2;
    for (i = 0; i < 16; ++i) {
        temp1 = ovec[i + num];
        temp2 = ovec[i + num + 1];
        ovec[i] = (temp1 << rem) | (temp2 >> (8 - rem));
        ovec[i + 8] = (temp2 << rem) | (temp1 >> (8 - rem)); // Additional computation with swapped operands
    }
}
