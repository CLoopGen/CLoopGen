#include <stdio.h>

#include <inttypes.h>

typedef unsigned int RC2_INT;

extern int i;
extern unsigned char *k;
extern RC2_INT *ki;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 126; i >= 0; i -= 4) {
        RC2_INT val1 = ((k[i + 1] << 8) | k[i]) & 65535;
        RC2_INT val2 = (i > 0) ? ((k[i - 1] << 8) | k[i - 2]) & 65535 : 0;
        if (i >= 2) *(ki--) = val2;
        *(ki--) = val1;
    }
}
