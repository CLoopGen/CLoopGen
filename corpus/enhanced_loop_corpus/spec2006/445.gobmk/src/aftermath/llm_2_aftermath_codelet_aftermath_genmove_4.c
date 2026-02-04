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
for (pos = 21; pos < 400; pos += 2) {
    int idx = pos + 1;
    if (idx < 400 && (board[idx] != 3) && score[idx] > best_score) {
        best_score = score[idx];
        move = idx;
    }
}
}
