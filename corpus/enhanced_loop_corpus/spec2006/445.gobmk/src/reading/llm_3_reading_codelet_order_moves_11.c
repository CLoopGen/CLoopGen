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
// Create an index array to enable indirect access pattern
int index[50];
for (int k = 0; k < moves->num; k++) {
    index[k] = k;
}
for (i = first_move; i < moves->num - 1; i++) {
    maxscore = moves->score[index[i]];
    max_at = i;
    for (j = i + 1; j < moves->num; j++) {
        if (moves->score[index[j]] > maxscore) {
            maxscore = moves->score[index[j]];
            max_at = j;
        }
    }
    if (max_at != i) {
        // Swap the indices to change access order indirectly
        int temp = index[max_at];
        index[max_at] = index[i];
        index[i] = temp;
        // Apply the swap in the original arrays using indirect indexing
        int pos_temp = moves->pos[index[i]];
        moves->pos[index[i]] = moves->pos[index[max_at]];
        moves->pos[index[max_at]] = pos_temp;
        moves->score[index[i]] = moves->score[index[max_at]];
        moves->score[index[max_at]] = maxscore;
    }
}
}
