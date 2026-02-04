#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = (i0 >> 1) - 1; i < (i1 >> 1) + 1; i++)
    p[2 * i + 1] -= (57862LL * (p[2 * i] + (int64_t)p[2 * i + 2]) + (1 << 15)) >> 16;

}
