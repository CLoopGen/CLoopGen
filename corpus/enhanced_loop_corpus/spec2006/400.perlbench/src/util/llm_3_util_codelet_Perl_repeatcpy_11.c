#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *to;
extern  char *from;
extern I32 len;
extern I32 todo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    I32 stride = 4;
    for (todo = (len + stride - 1) / stride * stride; todo > 0; todo -= stride) {
        if (todo >= stride) {
            *to++ = from[todo - stride];
            *to++ = from[todo - stride + 1];
            *to++ = from[todo - stride + 2];
            *to++ = from[todo - stride + 3];
        } else {
            for (I32 j = 0; j < todo; j++) {
                *to++ = from[todo - 1 - j];
            }
        }
    }
}
