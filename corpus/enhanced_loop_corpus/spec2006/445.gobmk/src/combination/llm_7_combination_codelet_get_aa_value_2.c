#include <stdio.h>

#include <inttypes.h>

extern int aa_values[400];
extern int stones[361];
extern int k;
extern int num_stones;
extern int value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    value = 0;
    for (int i = 0; i < num_stones; i++) {
        value += aa_values[stones[i]] * (i + 1);
    }
}
