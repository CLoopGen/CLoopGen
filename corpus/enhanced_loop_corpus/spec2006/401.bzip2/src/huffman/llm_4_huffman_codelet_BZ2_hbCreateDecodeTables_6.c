#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 23; i++) {
        if (i % 2 == 0) {
            base[i] = 0;
        } else {
            continue;
        }
    }
}
