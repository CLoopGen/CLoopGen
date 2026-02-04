#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double d1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    double local_d1 = d1;
    for (i = 0; i < 10; i += 2) {
        double next1 = 1 / (local_d1 + 1);
        double next2 = 1 / (next1 + 1);
        local_d1 = next2;
    }
    d1 = local_d1;
}
