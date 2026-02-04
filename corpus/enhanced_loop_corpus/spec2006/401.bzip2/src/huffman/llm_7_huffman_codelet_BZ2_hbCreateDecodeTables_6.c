#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 23; i += 2) {
        base[i] = 0;           // Write to even index
        if (i + 1 < 23) {
            base[i + 1] = 0;   // Write to odd index – no loop-carried dependence; independent iterations
        }
    }
}
