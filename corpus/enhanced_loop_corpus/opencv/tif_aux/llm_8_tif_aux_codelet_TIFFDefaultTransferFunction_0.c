#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t i;
extern tmsize_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n; i += 2) {
    double t1 = (double)i / ((double)n - 1.);
    double t2 = ((double)i + 1.) / ((double)n - 1.);
}
}
