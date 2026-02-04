#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern int *i;
extern IDWTELEM *low;
extern IDWTELEM *high;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_i = *i;
for (; temp_i >= 0; temp_i -= 2) {
    for (int unroll = 0; unroll < 1; ++unroll) {
        low[temp_i + 1] = high[temp_i >> 1];
        low[temp_i] = low[temp_i >> 1];
    }
}
*i = temp_i;
}
