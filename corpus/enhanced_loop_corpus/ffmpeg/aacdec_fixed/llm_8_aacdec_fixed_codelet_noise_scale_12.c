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
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            int64_t val1 = -(int64_t)coefs[i] * c * (1 << -s);
            int64_t val2 = -(int64_t)coefs[i + 1] * c * (1 << -s);
            coefs[i] = (int)val1;
            coefs[i + 1] = (int)val2;
        } else {
            coefs[i] = -(int64_t)coefs[i] * c * (1 << -s);
        }
    }
}
