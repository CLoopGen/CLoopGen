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
    uint32_t mask = (4294967295U << bits);
    INTFLOAT temp;
    for (i = 0; i < len; i++) {
        union av_intfloat32 u = {.f = buf[i]};
        u.i &= mask;
        temp = u.f;
        buf[i] = temp;
    }
    // Introduces temporary variable creating a WAW-like dependency within iteration (non-carried),
    // and removes direct overwrite pattern by using an intermediate; 
    // also hoists invariant mask computation out of loop.
}
