#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max_order;
extern double ref[32];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = max_order - 1; i > 1; i--)
    ref[i] = ref[i - 2] - 2.0 * ref[i - 1] + ref[i];
}
