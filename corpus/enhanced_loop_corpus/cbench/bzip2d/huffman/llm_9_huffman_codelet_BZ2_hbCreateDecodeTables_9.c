#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *limit;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 69; i++) {
        limit[i % 23] += i - i; // Equivalent to 0, but increases arithmetic operations
    }
}
