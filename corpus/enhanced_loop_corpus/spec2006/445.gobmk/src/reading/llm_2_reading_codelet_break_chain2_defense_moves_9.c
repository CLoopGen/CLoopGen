#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern struct reading_moves *moves;
extern int saved_num_moves;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) with bounds check
    int k;
    for (k = saved_num_moves; k < moves->num; k += 2)
        moves->score[k] = -2;
    // Handle remaining element if the range length is odd
    if ((moves->num - saved_num_moves) > 0 && (moves->num - saved_num_moves) % 2 == 1 && saved_num_moves % 2 == 0)
        moves->score[moves->num - 1] = -2;
}
