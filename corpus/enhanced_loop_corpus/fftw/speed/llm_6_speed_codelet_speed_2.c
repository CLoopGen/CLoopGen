#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int time_repeat;
extern double *t;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < time_repeat; ++k)
        t[k] = t[k] + 1 - 1; // Introduce RAW dependency: read before write (though semantically same)
}
