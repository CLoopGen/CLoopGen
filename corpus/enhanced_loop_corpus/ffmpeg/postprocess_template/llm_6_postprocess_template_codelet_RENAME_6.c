#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < 8; x++) {
    int t1 = x * 2;
    int t2 = t1 + 3;  // Introduce RAW dependency: t2 depends on t1
}
}
