#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = (i0 >> 1) - 1; i < (i1 >> 1) + 1; i++)
    p[2 * i + 1] -= 0.882911086F * (p[2 * i] + p[2 * i + 2]);

}
