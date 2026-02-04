#include <stdio.h>
#include <inttypes.h>

typedef unsigned char UChar;

typedef struct {
    UChar b[8];
} UInt64;

typedef int Int32;

UInt64 *n;
Int32 i;
double base;
double sum;

void init_vars() {
    const int data_size = 1 << 20; // 1MB of input data
    UInt64 *data = (UInt64*)__builtin_malloc(data_size * sizeof(UInt64));
    
    // Initialize data with predictable values
    for (int idx = 0; idx < data_size; idx++) {
        for (int j = 0; j < 8; j++) {
            data[idx].b[j] = (UChar)(idx + j) % 251;
        }
    }
    
    n = data;
    i = 0;
    base = 1.0;
    sum = 0.0;
}