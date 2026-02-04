#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *base;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 temp = 0;
    for (i = 0; i < 23; i++) {
        temp = temp + base[i];
        base[i] = temp;
        temp = base[i];
    }
}
