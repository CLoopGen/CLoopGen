#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;
extern int32_t *b0;
extern int32_t *b1;
extern int32_t *b2;
extern int32_t *b3;
extern int32_t *b4;
extern int32_t *b5;
extern int32_t *b6;
extern int32_t *b7;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (width > 64 ? 64 : width); i++) {
        int32_t combined = 0;
        combined += (b0[i] + b7[i]);
        combined -= (b1[i] + b6[i]) * 2;
        combined += (b2[i] + b5[i]) * 4;
        combined -= (b3[i] + b4[i]) * 8;
        combined = (combined + 64) >> 7;
        dst[i] = ((unsigned int)dst[i] + (unsigned int)combined);
    }
}
