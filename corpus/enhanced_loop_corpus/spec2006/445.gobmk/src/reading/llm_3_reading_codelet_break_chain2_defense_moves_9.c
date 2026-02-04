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
    // Variant 2: Indirect memory access using an index map (simulated with simple offset array)
    int indices[50];
    int n = 0;
    int k;
    // Precompute indirect indices (reversing the order within the range)
    for (k = saved_num_moves; k < moves->num; k++) {
        indices[n++] = k;
    }
    // Traverse in reverse order via the index array
    for (k = n - 1; k >= 0; k--)
        moves->score[indices[k]] = -2;
}
