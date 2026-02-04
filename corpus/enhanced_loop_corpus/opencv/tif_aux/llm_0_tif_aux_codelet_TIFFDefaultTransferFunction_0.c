#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t i;
extern tmsize_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (tmsize_t i = 1; i < n; i++) {
        for (tmsize_t j = 1; j < i; j++) {
            double t = (double)j / ((double)n - 1.);
        }
    }
}
