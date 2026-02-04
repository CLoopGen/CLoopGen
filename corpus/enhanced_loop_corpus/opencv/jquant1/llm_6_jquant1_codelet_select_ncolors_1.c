#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nc;
extern int iroot;
extern int i;
extern long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long local_temp = temp;
    for (i = 1; i < nc; i++)
        local_temp *= iroot;
    temp = local_temp;
}
