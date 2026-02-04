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
for (i = 0; i < len; i++) {
    for (int inner = 0; inner < 1; inner++) {
        union av_intfloat32 u = {.f = buf[i]};
        u.i &= (4294967295U << bits);
        buf[i] = u.f;
    }
}
}
