#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 23; i++) {
    if (i % 2 == 0)
        continue;
    base[i] += base[i - 1];
}
}
