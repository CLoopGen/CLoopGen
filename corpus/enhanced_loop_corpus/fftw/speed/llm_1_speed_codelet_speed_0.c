#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int time_repeat;
extern double *t;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < time_repeat; ++outer)
        for (int middle = 0; middle < 1; ++middle)
            for (k = 0; k < 1; ++k)
                t[outer] = 0;
}
