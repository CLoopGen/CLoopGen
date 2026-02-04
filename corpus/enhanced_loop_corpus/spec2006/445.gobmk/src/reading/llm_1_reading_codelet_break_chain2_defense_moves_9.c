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
if (saved_num_moves < moves->num) {
    for (k = saved_num_moves; k < moves->num; k += 2) {
        moves->score[k] = -2;
        if (k + 1 < moves->num)
            moves->score[k + 1] = -2;
    }
}
}
