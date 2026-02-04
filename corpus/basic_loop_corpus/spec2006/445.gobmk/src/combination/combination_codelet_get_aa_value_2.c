#include <stdio.h>

#include <inttypes.h>

extern int aa_values[400];
extern int stones[361];
extern int k;
extern int num_stones;
extern int value;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = 0; k < num_stones; k++)
    value += aa_values[stones[k]];

}
