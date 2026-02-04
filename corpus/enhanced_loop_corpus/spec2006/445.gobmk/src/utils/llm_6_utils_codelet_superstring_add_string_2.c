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
    int temp_value;
    for (k = 0; k < new_stones; k++) {
        if (do_add) {
            temp_value = my_stones[*num_my_stones + k];
            stones[*num_stones] = temp_value;
            (*num_stones) = (*num_stones) + 1;
        }
    }
}
