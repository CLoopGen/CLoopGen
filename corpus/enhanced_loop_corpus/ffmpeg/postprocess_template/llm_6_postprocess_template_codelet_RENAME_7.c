#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < 8; x++) {
    int t1 = x * 2;
    int t2 = t1 + 3;      // RAW dependency: t2 depends on t1
    int t3 = t2 * x;      // RAW dependency: t3 depends on t2 and x
}
}
