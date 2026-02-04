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
int k1, k2;
for (k1 = saved_num_moves; k1 < moves->num; k1++)
    for (k2 = 0; k2 < 1; k2++)
        moves->score[k1] = -2;
}
