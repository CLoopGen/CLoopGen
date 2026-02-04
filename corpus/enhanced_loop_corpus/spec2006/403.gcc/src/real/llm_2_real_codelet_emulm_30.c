#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern unsigned short b[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2, wrapping around using modulo
    int n = 6 + 3;
    for (i = 0; i < n; i++) {
        int idx = (i * 2) % n;  // Strided access: every second element, wrap if needed
        b[idx] = equot[idx];
    }
}
