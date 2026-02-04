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
for (i = first_move; i < moves->num - 1; i += 2) {
    maxscore = moves->score[i];
    max_at = i;
    for (j = i + 1; j < moves->num; j++) {
        if (moves->score[j] > maxscore) {
            maxscore = moves->score[j];
            max_at = j;
        }
    }
    if (max_at != i) {
        int temp_pos = moves->pos[max_at];
        int temp_score = moves->score[max_at];
        moves->pos[max_at] = moves->pos[i];
        moves->score[max_at] = moves->score[i];
        moves->pos[i] = temp_pos;
        moves->score[i] = temp_score;
    }
}
}
