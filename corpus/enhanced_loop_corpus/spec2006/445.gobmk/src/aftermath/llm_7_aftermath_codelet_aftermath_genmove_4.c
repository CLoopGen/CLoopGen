#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int score[400];
extern int move;
extern int pos;
extern int best_score;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_move = move;
    int local_best = best_score;
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos += 2) {
        if ((board[pos] != 3) && score[pos] > local_best) {
            local_best = score[pos];
            local_move = pos;
        }
    }
    for (pos = (19 + 2) + 1; pos < (19 + 1) * (19 + 1); pos += 2) {
        if ((board[pos] != 3) && score[pos] > local_best) {
            local_best = score[pos];
            local_move = pos;
        }
    }
    best_score = local_best;
    move = local_move;
}
