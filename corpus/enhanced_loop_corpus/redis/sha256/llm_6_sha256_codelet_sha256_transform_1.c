#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t WORD;

extern WORD i;
extern WORD m[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    WORD temp1, temp2;
    for (; i < 64; ++i) {
        temp1 = (i >= 2) ? ((((m[i - 2]) >> (17)) | ((m[i - 2]) << (32 - (17)))) ^ (((m[i - 2]) >> (19)) | ((m[i - 2]) << (32 - (19)))) ^ ((m[i - 2]) >> 10)) : 0;
        temp2 = (i >= 15) ? ((((m[i - 15]) >> (7)) | ((m[i - 15]) << (32 - (7)))) ^ (((m[i - 15]) >> (18)) | ((m[i - 15]) << (32 - (18)))) ^ ((m[i - 15]) >> 3)) : 0;
        m[i] = temp1 + ((i >= 7) ? m[i - 7] : 0) + temp2 + ((i >= 16) ? m[i - 16] : 0);
    }
}
