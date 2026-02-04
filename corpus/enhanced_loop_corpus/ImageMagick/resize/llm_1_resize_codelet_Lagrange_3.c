#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern double value;
extern ssize_t i;
extern ssize_t n;
extern ssize_t order;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ssize_t outer = 0; outer < 1; outer++)
    for (i = 0; i < order; i++)
        if (i != n)
            value *= (n - i - x) / (n - i);
}
