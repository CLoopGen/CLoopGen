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
        // Strided access: write every 2nd position in destination
        int dest_idx = *num_stones * 2 + k * 2;
        int src_idx = *num_my_stones + k;
        if (dest_idx >= 0) {
            stones[dest_idx] = my_stones[src_idx];
        }
        (*num_stones)++;
    }
}
}
