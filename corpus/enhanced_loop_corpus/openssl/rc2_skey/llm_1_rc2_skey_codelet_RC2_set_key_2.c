#include <stdio.h>

#include <inttypes.h>

typedef unsigned int RC2_INT;

extern int i;
extern unsigned char *k;
extern RC2_INT *ki;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 127; i >= 0; i -= 4) {
        if (i >= 0) *(ki--) = ((k[i] << 8) | k[i - 1]) & 65535;
        if (i >= 2) *(ki--) = ((k[i-2] << 8) | k[i - 3]) & 65535;
    }
}
