#include <stdio.h>

#include <inttypes.h>

extern int aa_values[400];
extern int stones[361];
extern int k;
extern int num_stones;
extern int value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_value = 0;
    int stride = 4;
    int limit = (num_stones / stride) * stride;
    for (k = 0; k < limit; k += stride) {
        temp_value += aa_values[stones[k]];
        temp_value += aa_values[stones[k + 1]];
        temp_value += aa_values[stones[k + 2]];
        temp_value += aa_values[stones[k + 3]];
    }
    for (; k < num_stones; k++) {
        temp_value += aa_values[stones[k]];
    }
    value += temp_value;
}
