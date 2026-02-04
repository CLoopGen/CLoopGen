#include <stdio.h>

#include <inttypes.h>

extern int *num_my_stones;
extern int *my_stones;
extern int *num_stones;
extern int *stones;
extern int do_add;
extern int new_stones;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < new_stones; k++) {
    if (do_add) {
        int idx = *num_my_stones + k;
        stones[*num_stones + k] = my_stones[idx];
        // Perform consecutive write into stones starting from current num_stones
    }
}
// Update counter once after loop to reflect bulk addition
if (do_add) {
    *num_stones += new_stones;
}
}
