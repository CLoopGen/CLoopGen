#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t WORD;

extern WORD i;
extern WORD m[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (WORD outer = 0; outer < 1; ++outer)
        for (; i < 64; ++i)
            m[i] = ((((m[i - 2]) >> (17)) | ((m[i - 2]) << (32 - (17)))) ^ (((m[i - 2]) >> (19)) | ((m[i - 2]) << (32 - (19)))) ^ ((m[i - 2]) >> 10)) + m[i - 7] + ((((m[i - 15]) >> (7)) | ((m[i - 15]) << (32 - (7)))) ^ (((m[i - 15]) >> (18)) | ((m[i - 15]) << (32 - (18)))) ^ ((m[i - 15]) >> 3)) + m[i - 16];
}
