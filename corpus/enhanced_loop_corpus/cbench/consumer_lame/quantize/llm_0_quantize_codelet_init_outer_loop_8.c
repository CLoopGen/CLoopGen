#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];
extern FLOAT8 mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int b_outer, b_inner;
mx = -1.0 / 0.0; // Negative infinity to ensure max works correctly
for (b_outer = 0; b_outer < 3; b_outer++) {
    for (b_inner = 0; b_inner < 1; b_inner++) {
        b = b_outer;
        mx = ((mx) > (en[b]) ? (mx) : (en[b]));
    }
}
}
