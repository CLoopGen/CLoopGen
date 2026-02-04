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
    int prev_index = saved_num_moves;
    for (int delta = 0; delta < moves->num - saved_num_moves; delta++) {
        int k = prev_index + delta;
        if (delta > 0) {
            moves->score[k] = moves->score[k-1]; // Introduce WAW and loop-carried dependence
        } else {
            moves->score[k] = -2;
        }
    }
}
