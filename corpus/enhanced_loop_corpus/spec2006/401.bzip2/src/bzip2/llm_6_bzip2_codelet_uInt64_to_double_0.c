#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef struct {
    UChar b[8];
} UInt64;

typedef int Int32;

extern UInt64 *n;
extern Int32 i;
extern double base;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    double temp_sum = 0.0;
    double temp_base = base;
    for (i = 0; i < 8; i++) {
        temp_sum += temp_base * (double)(n->b[i]);
        temp_base *= 256.0;
    }
    sum += temp_sum;
}
