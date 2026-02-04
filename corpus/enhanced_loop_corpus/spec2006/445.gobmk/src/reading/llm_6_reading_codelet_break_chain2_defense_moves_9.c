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
    int temp_score[50];
    for (int i = saved_num_moves; i < moves->num; i++) {
        temp_score[i] = -2;
    }
    for (int i = saved_num_moves; i < moves->num; i++) {
        moves->score[i] = temp_score[i];
    }
}
