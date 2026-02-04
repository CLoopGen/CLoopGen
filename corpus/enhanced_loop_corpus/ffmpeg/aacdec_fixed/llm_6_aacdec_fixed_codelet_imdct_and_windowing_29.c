#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *buf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1024; i += 2) {
        buf[i] = (buf[i] + 4LL) >> 3;
        if (i + 1 < 1024)
            buf[i + 1] = (buf[i + 1] + 4LL) >> 3;
    }
}
