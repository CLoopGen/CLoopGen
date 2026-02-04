#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double value;
extern double result;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_result = 1.0;
    for (i = 0; i < (ssize_t)value; i++) {
        local_result *= 2.;
        result = local_result; // Introduce WAW dependency with repeated write to 'result'
    }
}
