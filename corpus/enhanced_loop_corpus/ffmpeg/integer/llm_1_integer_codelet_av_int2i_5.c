#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

extern int64_t a;
extern AVInteger out;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        out.v[i] = a;
        a >>= 16;
    }
    for (i = 4; i < 8; i++) {
        out.v[i] = a;
        a >>= 16;
    }
}
