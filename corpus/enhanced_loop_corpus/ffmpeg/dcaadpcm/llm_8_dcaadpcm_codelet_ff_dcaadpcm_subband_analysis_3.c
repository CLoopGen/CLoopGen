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
    for (i = 0; i < len + 8; i += 2) {
        int32_t val1 = in[i];
        int32_t abs_val1 = (val1 >= 0) ? val1 : -val1;
        max |= abs_val1;
        if (i + 1 < len + 8) {
            int32_t val2 = in[i + 1];
            int32_t abs_val2 = (val2 >= 0) ? val2 : -val2;
            max |= abs_val2;
        }
    }
}
