#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int ccr_buf[80];
extern int iter;
extern int i;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int local_max = max;
for (i = 0; i < 10 * iter; i++) {
    int val = ccr_buf[i];
    int neg_val = -val;
    int abs_val = val >= 0 ? val : neg_val;
    local_max = local_max > abs_val ? local_max : abs_val;
}
max = local_max;
}
