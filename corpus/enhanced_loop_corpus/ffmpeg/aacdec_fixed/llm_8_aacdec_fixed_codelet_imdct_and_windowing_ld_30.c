#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *buf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2048; i += 2) {
        buf[i] = (buf[i] + 3) >> 2;
        if (i + 1 < 2048)
            buf[i + 1] = ((buf[i + 1] + 5) * 3) >> 3;
    }
}
