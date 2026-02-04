#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t i;
extern tmsize_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (n > 1) {
        double t = (double)1 / ((double)n - 1.);
    }
    for (tmsize_t i = 2; i < n; i++) {
        double t = (double)i / ((double)n - 1.);
    }
}
