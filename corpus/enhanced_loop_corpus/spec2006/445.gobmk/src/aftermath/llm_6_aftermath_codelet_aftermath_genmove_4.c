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
    int temp_best = best_score;
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
        int current_score = score[pos];
        if ((board[pos] != 3) && current_score > temp_best) {
            temp_best = current_score;
            move = pos;
        }
    }
    best_score = temp_best;
}
