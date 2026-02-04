#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *coefs;
extern int len;
extern int s;
extern int i;
extern int c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (c == 0 || s >= 32 || s <= -32) {
        return;
    }
    for (i = 0; i < len; i++) {
        coefs[i] = -(int64_t)coefs[i] * c * (1 << -s);
    }
}
