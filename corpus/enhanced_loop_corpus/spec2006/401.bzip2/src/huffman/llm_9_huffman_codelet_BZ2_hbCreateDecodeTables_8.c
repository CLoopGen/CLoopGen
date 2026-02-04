#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 12; i++) {
        Int32 temp1 = base[i - 1];
        base[i] += temp1;
        if (i + 1 < 23) {
            base[i + 1] += temp1 + base[i];
        }
    }
}
