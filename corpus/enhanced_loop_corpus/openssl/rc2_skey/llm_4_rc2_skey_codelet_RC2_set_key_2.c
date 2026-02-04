#include <stdio.h>

#include <inttypes.h>

typedef unsigned int RC2_INT;

extern int i;
extern unsigned char *k;
extern RC2_INT *ki;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 127; i >= 0; i -= 2) {
        if (k[i] != 0 || k[i - 1] != 0) {
            *(ki--) = ((k[i] << 8) | k[i - 1]) & 65535;
        }
    }
}
