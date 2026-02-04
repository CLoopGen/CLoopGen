#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 23; i++) {
        for (Int32 inner = 0; inner < 1; inner++) {
            base[i] = 0;
        }
    }
}
