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
    int prev_index = 0;
    if (len > 0) coefs[0] = -(int64_t)coefs[0] * c * (1 << -s);
    for (i = 1; i < len; i++) {
        coefs[i] = -(int64_t)coefs[prev_index] * c * (1 << -s);
        prev_index = i;
    }
}
