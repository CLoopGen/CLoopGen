#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *buf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; i++) {
        INTFLOAT temp1 = buf[2*i] + 1;
        INTFLOAT temp2 = buf[2*i + 1] + 1;
        buf[2*i] = temp1 >> 1;
        buf[2*i + 1] = temp2 >> 1;
    }
}
