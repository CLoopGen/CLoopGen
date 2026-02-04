#include <stdio.h>

#include <inttypes.h>

extern int aa_values[400];
extern int stones[361];
extern int k;
extern int num_stones;
extern int value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (k = 0; k < num_stones; k += 2) {
        if (k + 1 < num_stones) {
            value += aa_values[stones[k]] + aa_values[stones[k + 1]];
        } else {
            value += aa_values[stones[k]];
        }
    }
}
