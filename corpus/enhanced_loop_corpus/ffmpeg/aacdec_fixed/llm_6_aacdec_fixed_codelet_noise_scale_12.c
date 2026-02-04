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
    int temp = 0;
    for (i = 0; i < len; i++) {
        temp = -(int64_t)coefs[i] * c * (1 << -s);
        coefs[i] = temp;
    }
}
