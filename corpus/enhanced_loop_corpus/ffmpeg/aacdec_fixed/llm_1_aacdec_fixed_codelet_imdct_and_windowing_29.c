#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *buf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i++) {
        buf[i] = (buf[i] + 4LL) >> 3;
        buf[i + 256] = (buf[i + 256] + 4LL) >> 3;
        buf[i + 512] = (buf[i + 512] + 4LL) >> 3;
        buf[i + 768] = (buf[i + 768] + 4LL) >> 3;
    }
}
