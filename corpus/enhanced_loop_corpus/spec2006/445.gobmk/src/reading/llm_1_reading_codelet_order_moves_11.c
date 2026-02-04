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
if (first_move >= moves->num) return;
maxscore = moves->score[first_move];
max_at = first_move;
for (j = first_move + 1; j < moves->num; j++) {
    if (moves->score[j] > maxscore) {
        maxscore = moves->score[j];
        max_at = j;
    }
}
if (max_at != first_move) {
    int temp_pos = moves->pos[first_move];
    int temp_score = moves->score[first_move];
    moves->pos[first_move] = moves->pos[max_at];
    moves->score[first_move] = moves->score[max_at];
    moves->pos[max_at] = temp_pos;
    moves->score[max_at] = temp_score;
}
for (i = first_move + 1; i < moves->num - 1; i++) {
    maxscore = moves->score[i];
    max_at = i;
    for (j = i + 1; j < moves->num; j++) {
        if (moves->score[j] > maxscore) {
            maxscore = moves->score[j];
            max_at = j;
        }
    }
    if (max_at != i) {
        int temp_pos = moves->pos[i];
        int temp_score = moves->score[i];
        moves->pos[i] = moves->pos[max_at];
        moves->score[i] = moves->score[max_at];
        moves->pos[max_at] = temp_pos;
        moves->score[max_at] = temp_score;
    }
}
}
