#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  ssize_t n;
extern  ssize_t k;
extern double r;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_r = 1.0;
    for (i = 1; i <= (n - k); i++)
        local_r *= i;
    r = r / local_r;
}
