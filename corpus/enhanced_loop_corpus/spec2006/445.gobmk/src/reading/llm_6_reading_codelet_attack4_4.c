#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern int k;
extern struct reading_moves moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_score[50];
    for (int i = 0; i < moves.num; i++) {
        temp_score[i] = moves.score[i] + 5;
    }
    for (int i = 0; i < moves.num; i++) {
        moves.score[i] = temp_score[i];
    }
}
