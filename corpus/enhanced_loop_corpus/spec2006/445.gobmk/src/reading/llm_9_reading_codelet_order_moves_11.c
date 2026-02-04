#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern struct reading_moves *moves;
extern int first_move;
extern int i;
extern int j;
extern int maxscore;
extern int max_at;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = first_move; i < moves->num; i++) {
    maxscore = moves->score[i];
    max_at = i;
    for (j = i; j < moves->num; j++) {
        if (moves->score[j] >= maxscore) {
            maxscore = moves->score[j];
            max_at = j;
        }
    }
    if (max_at != i) {
        int temp = moves->pos[i];
        moves->pos[i] = moves->pos[max_at];
        moves->pos[max_at] = temp;
        temp = moves->score[i];
        moves->score[i] = moves->score[max_at];
        moves->score[max_at] = temp;
    }
}
}
