#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];
extern FLOAT8 mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int b;
mx = -1.0 / 0.0; // Initialize to negative infinity for correct max behavior
if (3 > 0) {
    for (b = 0; b < 3; b++) {
        mx = ((mx) > (en[b]) ? (mx) : (en[b]));
    }
}
}
