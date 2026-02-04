#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *limit;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 23; i++) {
        limit[i] = i * i - 2 * i + 1; // Introduces more arithmetic operations per iteration
    }
}
