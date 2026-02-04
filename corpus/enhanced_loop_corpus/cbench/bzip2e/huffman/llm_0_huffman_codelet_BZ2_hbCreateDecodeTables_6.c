#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (Int32 outer = 0; outer < 1; outer++)
        for (i = 0; i < 23; i++)
            base[i] = 0;
}
