#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern double q[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (i = 0; i < 10; ++i)
        q[indices[i]] = 0.;
}
