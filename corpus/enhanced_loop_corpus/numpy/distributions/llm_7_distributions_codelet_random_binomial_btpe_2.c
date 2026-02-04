#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double a;
extern double s;
extern double F;
extern int64_t m;
extern int64_t y;
extern int64_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_F = F;
    for (i = m + 1; i <= y; i++) {
        local_F = local_F * (a / i - s);
        F = local_F; // Introduce WAW dependency: write-after-write on F
    }
}
