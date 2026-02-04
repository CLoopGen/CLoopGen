#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *buf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 1024; ++i) {
        int temp = buf[i] + 1;
        if (temp > 1) {
            buf[i] = temp >> 1;
        }
    }
}
