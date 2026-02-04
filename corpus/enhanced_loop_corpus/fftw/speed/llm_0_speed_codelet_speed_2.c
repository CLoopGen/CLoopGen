#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int time_repeat;
extern double *t;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < time_repeat; ++i)
        for (k = 0; k < 1; ++k)
            t[i] = 0;
}
