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
for (i = first_move; i < moves->num - 1; i++) {
    maxscore = moves->score[i];
    max_at = 0;
    for (j = i + 1; j < moves->num; j += 2) { // Strided access: step by 2
        if (j >= moves->num) break;
        if (moves->score[j] > maxscore) {
            maxscore = moves->score[j];
            max_at = j;
        }
    }
    // Handle odd indices in a second pass if needed for completeness
    for (j = i + 1 + (i % 2); j < moves->num; j += 2) {
        if (moves->score[j] > maxscore) {
            maxscore = moves->score[j];
            max_at = j;
        }
    }
    if (max_at != 0) {
        int temp = moves->pos[max_at];
        moves->pos[max_at] = moves->pos[i];
        moves->score[max_at] = moves->score[i];
        moves->pos[i] = temp;
        moves->score[i] = maxscore;
    }
}
}
