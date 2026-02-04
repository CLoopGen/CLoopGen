#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < cc; i += 2) {
    if (i + 1 < cc) {
        // Simulate two iterations in one unrolled step
        volatile tmsize_t dummy1 = i;
        volatile tmsize_t dummy2 = i + 1;
    }
}
}
