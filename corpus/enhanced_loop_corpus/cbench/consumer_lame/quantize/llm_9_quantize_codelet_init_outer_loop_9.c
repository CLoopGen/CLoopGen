#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];
extern FLOAT8 mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int b;
    FLOAT8 inv_mx = 1.0 / mx;
    FLOAT8 threshold = 9.9999999999999998E-13;
    for (b = 0; b < 6; b++) {
        int idx = b % 3;
        en[idx] = (en[idx] > threshold ? en[idx] : threshold) * inv_mx;
    }
}
