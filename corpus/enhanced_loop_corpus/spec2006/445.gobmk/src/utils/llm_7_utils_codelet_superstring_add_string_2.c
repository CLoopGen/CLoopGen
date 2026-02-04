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
    int local_count = *num_stones;
    for (k = 0; k < new_stones; k++) {
        if (do_add) {
            stones[local_count + k] = my_stones[*num_my_stones + k];
        }
    }
    if (do_add) {
        *num_stones = local_count + new_stones;
    }
}
