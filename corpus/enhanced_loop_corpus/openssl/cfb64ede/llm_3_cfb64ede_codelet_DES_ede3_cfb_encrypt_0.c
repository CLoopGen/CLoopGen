#include <stdio.h>

#include <inttypes.h>

extern int num;
extern int i;
extern unsigned char ovec[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse-order traversal with dependent access pattern
    for (i = 7; i >= 0; --i) {
        int next_idx = (i > 0) ? i - 1 : 0;
        ovec[i] <<= num % 8;
        ovec[i] |= ovec[next_idx] >> (8 - num % 8);
    }
}
