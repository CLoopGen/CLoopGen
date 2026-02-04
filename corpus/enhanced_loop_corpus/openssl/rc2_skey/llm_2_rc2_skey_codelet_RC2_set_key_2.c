#include <stdio.h>

#include <inttypes.h>

typedef unsigned int RC2_INT;

extern int i;
extern unsigned char *k;
extern RC2_INT *ki;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward iteration and index remapping
    RC2_INT temp[64];
    int idx = 0;
    for (i = 0; i < 128; i += 2) {
        temp[idx] = ((k[127 - i] << 8) | k[126 - i]) & 65535;
        idx++;
    }
    // Copy reversed order to ki (simulating original decrementing ki behavior)
    for (i = 0; i < 64; i++) {
        ki[63 - i] = temp[i];
    }
}
