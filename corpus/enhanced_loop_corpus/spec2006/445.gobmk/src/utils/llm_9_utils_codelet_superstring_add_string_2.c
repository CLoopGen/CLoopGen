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
    int step = (new_stones > 100) ? 3 : 1;
    int i;
    for (i = 0; i < new_stones; i += step) {
        if (do_add) {
            int idx = *num_my_stones + i;
            stones[*num_stones] = my_stones[idx];
            (*num_stones)++;
        }
    }
}
