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
int step = (bits > 0) ? bits : 1;
for (i = 0; i < len; i++) {
    union av_intfloat32 u = {.f = buf[i]};
    for (int j = 0; j < step; j++) {
        u.i &= (4294967295U >> (j % 8));
    }
    buf[i] = u.f;
}
}
