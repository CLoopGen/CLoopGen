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
    best_score = -2147483648;
    move = 0;
    for (pos = 21; pos < 361; pos++) {
        int index = pos + 19;
        if (index < 421 && board[index] != 3 && score[pos] > best_score) {
            best_score = score[pos];
            move = pos;
        }
    }
}
