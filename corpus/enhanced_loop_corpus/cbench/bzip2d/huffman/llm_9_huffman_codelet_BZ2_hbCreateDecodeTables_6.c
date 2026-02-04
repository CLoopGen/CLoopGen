#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 j;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 3; j++) {
            base[i * 3 + j] = (i + 1) * (j + 1);
        }
    }
}
