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
int start = (i0 >> 2);
int end = (i1 >> 2) + 1;
for (i = start; i < end; i += 2)
{
    int idx = 4 * i;
    p[idx + 1] -= 0.882911086F * (p[idx] + p[idx + 2]);
    p[idx + 3] -= 0.882911086F * (p[idx + 2] + p[idx + 4]);
}

}
