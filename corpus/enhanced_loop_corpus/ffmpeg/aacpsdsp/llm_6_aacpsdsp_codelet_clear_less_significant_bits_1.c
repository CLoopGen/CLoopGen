#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

union av_intfloat32 {
    uint32_t i;
    float f;
};


extern INTFLOAT *buf;
extern int len;
extern int bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (bits >= 32) {
        for (i = 0; i < len; i++) {
            buf[i] = 0.0f;
        }
    } else {
        uint32_t mask = (4294967295U << bits);
        for (i = 0; i < len; i++) {
            union av_intfloat32 u = {.f = buf[i]};
            u.i &= mask;
            buf[i] = u.f;
        }
    }
}
