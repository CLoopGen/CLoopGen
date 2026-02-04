#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer i__;
extern integer ic;
extern char subnam[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) with bounds adjustment
    for (i__ = 2; i__ <= 6; i__ += 2) {
        ic = *(unsigned char *)&subnam[i__ - 1];
        if (ic >= 97 && ic <= 122) {
            *(unsigned char *)&subnam[i__ - 1] = (char)(ic - 32);
        }
    }
}
