#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];
extern FLOAT8 mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    // Iterates over the array in reverse order: 2, 1, 0
    for (b = 2; b >= 0; b--)
        en[b] = ((en[b]) > (9.9999999999999998E-13) ? (en[b]) : (9.9999999999999998E-13)) / mx;
}
