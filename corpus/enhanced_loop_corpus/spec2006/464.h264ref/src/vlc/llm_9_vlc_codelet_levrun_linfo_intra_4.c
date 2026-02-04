#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8 && nn > 1; i++) {
    nn = (nn >> 1) + (nn >> 2);
}
}
