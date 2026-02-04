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
    if (len > 0) {
        i = 0;
        for (int outer = 0; outer < 1; outer++) {
            for (; i < len; i++) {
                coefs[i] = -(int64_t)coefs[i] * c * (1 << -s);
            }
        }
    }
}
