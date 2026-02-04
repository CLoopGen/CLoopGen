#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int n;
extern int32_t *smp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < 1; j++)
    for (i = 1; i < n; i++)
        if (smp[i] != smp[0])
            break;
}
