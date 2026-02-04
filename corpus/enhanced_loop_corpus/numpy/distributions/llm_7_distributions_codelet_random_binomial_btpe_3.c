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
    for (i = y + 1; i <= m; i++) {
        double denom = (a / i - s);
        if (denom != 0.0) {
            local_F = (local_F + a) / denom;
        } else {
            local_F += 1.0;
        }
    }
    F = local_F;
}
