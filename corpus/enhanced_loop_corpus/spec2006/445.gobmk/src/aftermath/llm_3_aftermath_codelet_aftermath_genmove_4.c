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
for (pos = 21; pos < 400; pos++) {
    int idx = (pos * 3) % 397; // Strided indirect access using prime modulus for dispersion
    if ((board[idx] != 3) && score[idx] > best_score) {
        best_score = score[idx];
        move = idx;
    }
}
}
