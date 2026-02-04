#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t WORD;

extern WORD i;
extern WORD m[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 32; ++i) {
        WORD temp1 = m[i - 2];
        WORD rotated_right_17 = (temp1 >> 17) | (temp1 << (32 - 17));
        WORD rotated_right_19 = (temp1 >> 19) | (temp1 << (32 - 19));
        WORD shr_10 = temp1 >> 10;
        WORD s0 = rotated_right_17 ^ rotated_right_19 ^ shr_10;

        WORD temp2 = m[i - 15];
        WORD rotated_right_7 = (temp2 >> 7) | (temp2 << (32 - 7));
        WORD rotated_right_18 = (temp2 >> 18) | (temp2 << (32 - 18));
        WORD shr_3 = temp2 >> 3;
        WORD s1 = rotated_right_7 ^ rotated_right_18 ^ shr_3;

        m[i] = s0 + m[i - 7] + s1 + m[i - 16];
    }
}
