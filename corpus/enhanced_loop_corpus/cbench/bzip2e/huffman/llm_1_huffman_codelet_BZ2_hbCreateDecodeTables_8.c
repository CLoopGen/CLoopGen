#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (Int32 outer = 1; outer <= 5; outer++)
    for (i = 1; i < 23; i++)
        base[i] += base[i - 1];
}
