#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 10; i++) {
        base[i] += base[i - 1];
        base[i + 10] += base[i + 9];
        base[i + 20] += base[i + 19];
    }
}
