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
    int i;
    for (i = 0; i < new_stones * 2; i += 2) {
        if (do_add && (i + 1) < new_stones) {
            stones[*num_stones] = my_stones[*num_my_stones + i];
            (*num_stones)++;
            stones[*num_stones] = my_stones[*num_my_stones + i + 1];
            (*num_stones)++;
        } else if (do_add) {
            stones[*num_stones] = my_stones[*num_my_stones + i];
            (*num_stones)++;
        }
    }
}
