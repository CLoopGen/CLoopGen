#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 23; i++) {
        base[i] += base[i - 1];
        for (Int32 k = 0; k < 1; k++) {
        }
    }
}
