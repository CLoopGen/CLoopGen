#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];
extern FLOAT8 mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, wrapping around using modulo)
    // This changes the access pattern from sequential to strided: b = 0, 2, 1 (since 4 % 3 = 1)
    for (int i = 0; i < 3; i++) {
        int b = (i * 2) % 3;
        en[b] = ((en[b]) > (9.9999999999999998E-13) ? (en[b]) : (9.9999999999999998E-13)) / mx;
    }
}
