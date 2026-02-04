#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

extern UInt32 *ftab;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 1; outer <= 65536; outer++) {
        for (int inner = 0; inner < 1; inner++) {
            ftab[outer] += ftab[outer - 1];
        }
    }
}
