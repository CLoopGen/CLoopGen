#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *buf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INTFLOAT temp = buf[0];
    for (i = 0; i < 1024; i++) {
        INTFLOAT next_temp = buf[i];
        buf[i] = (temp + 4LL) >> 3;
        temp = next_temp;
    }
}
