#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *in;
extern int len;
extern int i;
extern int32_t max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    max = 0;
    for (i = 0; i < len + 4; i++) {
        int32_t abs_val = in[i];
        abs_val = (abs_val ^ (abs_val >> 31)) - (abs_val >> 31); // Branchless absolute value
        if (abs_val > max || i == 0) {
            max = abs_val;
        }
    }
}
