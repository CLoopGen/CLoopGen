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
    double local_base = base;
    for (i = 0; i < 8; i++) {
        double val = (double)(n->b[i]);
        sum += local_base * val;
        local_base = local_base * 256.0;
    }
}
