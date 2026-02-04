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
    for (i = 0; i < 16; i++) {
        Int32 index = i >> 1;
        double factor = (i & 1) ? base * 256.0 : base;
        sum += factor * (double)(n->b[index]);
        if (i & 1) base *= 65536.0;
    }
}
