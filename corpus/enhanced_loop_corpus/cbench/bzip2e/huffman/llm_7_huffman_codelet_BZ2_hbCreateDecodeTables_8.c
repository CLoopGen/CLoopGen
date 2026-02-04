#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 23; i += 2) {
        if (i + 1 < 23) {
            base[i] += base[i - 1];
            base[i + 1] += base[i]; // introduces stronger WAW and RAW dependencies
        } else {
            base[i] += base[i - 1];
        }
    }
}
