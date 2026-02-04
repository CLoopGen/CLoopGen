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
    int stride = 4;
    for (i = 0; i < len; i++) {
        int64_t acc = 0;
        for (int j = 0; j < stride && (i + j) < len; j++) {
            acc += -(int64_t)coefs[i + j] * c;
        }
        acc = (acc >> -s);
        coefs[i] = (int)acc;
        for (int j = 1; j < stride && (i + j) < len; j++) {
            coefs[i + j] = -(int64_t)coefs[i + j] * c * (1 << -s);
        }
        i += stride - 1;
    }
}
