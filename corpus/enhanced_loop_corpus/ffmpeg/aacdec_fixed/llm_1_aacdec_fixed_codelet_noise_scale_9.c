#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *coefs;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (len > 0) {
    for (i = 0; i < len; i += 2) {
        coefs[i] = 0;
        if (i + 1 < len) {
            coefs[i + 1] = 0;
        }
    }
}
}
