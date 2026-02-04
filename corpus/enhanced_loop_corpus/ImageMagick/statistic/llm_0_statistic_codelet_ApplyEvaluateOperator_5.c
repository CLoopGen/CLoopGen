#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double value;
extern double result;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t outer = 0; outer < (ssize_t)value; outer++)
        for (i = 0; i < 1; i++)
            result /= 2.;
}
