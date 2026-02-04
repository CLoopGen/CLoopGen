#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];
extern FLOAT8 mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int b_outer, b_inner;
for (b_outer = 0; b_outer < 3; b_outer++) {
    for (b_inner = 0; b_inner < 1; b_inner++) {
        b = b_outer;
        en[b] = ((en[b]) > (9.9999999999999998E-13) ? (en[b]) : (9.9999999999999998E-13)) / mx;
    }
}
}
