#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t i;
extern tmsize_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_t = 0.0;
    for (i = 1; i < n; i++) {
        double t = ((double)i / ((double)n - 1.)) + prev_t;
        prev_t = t;
    }
}
