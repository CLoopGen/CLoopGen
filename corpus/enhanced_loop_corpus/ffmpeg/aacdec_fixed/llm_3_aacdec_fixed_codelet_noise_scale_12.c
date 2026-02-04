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
    // Variant 2: Reverse consecutive memory access (process array from end to beginning)
    for (i = len - 1; i >= 0; i--) {
        coefs[i] = -(int64_t)coefs[i] * c * (1 << -s);
    }
}
