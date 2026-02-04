#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t WORD;

extern WORD i;
extern WORD m[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 64; ++i) {
        if (i >= 16) {
            WORD temp1 = ((((m[i - 2]) >> 17) | (m[i - 2] << 15)) ^ ((m[i - 2] >> 19) | (m[i - 2] << 13)) ^ (m[i - 2] >> 10));
            WORD temp2 = ((((m[i - 15]) >> 7) | (m[i - 15] << 25)) ^ ((m[i - 15] >> 18) | (m[i - 15] << 14)) ^ (m[i - 15] >> 3));
            m[i] = temp1 + m[i - 7] + temp2 + m[i - 16];
        } else {
            m[i] = 0;
        }
    }
}
