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
    double local_base[8];
    local_base[0] = base;
    for (i = 1; i < 8; i++) {
        local_base[i] = local_base[i-1] * 256.0;
    }
    for (i = 0; i < 8; i++) {
        sum += local_base[i] * (double)(n->b[i]);
    }
}
