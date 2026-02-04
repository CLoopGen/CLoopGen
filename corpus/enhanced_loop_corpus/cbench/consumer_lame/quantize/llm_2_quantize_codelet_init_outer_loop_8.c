#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];
extern FLOAT8 mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 1, but traversed in reverse order)
    for (b = 2; b >= 0; b--)
        mx = ((mx) > (en[b]) ? (mx) : (en[b]));
}
