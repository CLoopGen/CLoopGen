#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern ssize_t i;
extern ssize_t end;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = (ssize_t)255; i >= 0; i--)
    if (histogram[i] > 0.) {
        end = i;
        break;
    }

}
