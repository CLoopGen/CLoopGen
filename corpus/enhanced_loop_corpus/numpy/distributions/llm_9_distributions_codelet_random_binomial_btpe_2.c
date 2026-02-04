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
int64_t step = 1;
for (i = m + 1; i <= y; i += step) {
    double temp1 = a / i;
    double temp2 = temp1 - s;
    F = F * temp2 * temp2; // Square the update to increase arithmetic intensity
    step = 1 + ((i - m) & 1); // Alternate increment between 1 and 2 to vary trip count
}
}
