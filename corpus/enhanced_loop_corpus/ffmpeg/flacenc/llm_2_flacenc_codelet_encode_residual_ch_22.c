#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int n;
extern int32_t *smp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < n; i += 2)
    if (smp[i] != smp[0])
        break;
}
