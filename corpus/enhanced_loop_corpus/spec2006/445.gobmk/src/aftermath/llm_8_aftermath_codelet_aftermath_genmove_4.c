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
    int start = 21;
    int end = 400;
    best_score = -1;
    move = 0;
    for (pos = start; pos < end; pos += 2) {
        if ((board[pos] != 3) && score[pos] > best_score) {
            best_score = score[pos];
            move = pos;
        }
    }
}
