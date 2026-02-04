#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (Int32 j = 0; j < 1; j++)
        for (i = 0; i < 23; i++)
            base[i] = 0;
}
