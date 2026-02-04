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
for (; temp_i >= 2; temp_i -= 4) {
    for (int j = 0; j < 2 && (temp_i - 2*j) >= 0; ++j) {
        int idx = temp_i - 2*j;
        low[idx + 1] = high[idx >> 1];
        low[idx] = low[idx >> 1];
    }
}
*i = temp_i;
}
