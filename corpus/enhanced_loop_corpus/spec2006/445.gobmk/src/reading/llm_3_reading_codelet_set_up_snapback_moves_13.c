#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern struct reading_moves *moves;
extern int libs2[2];
extern int u;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int num = (*moves).num;
    int *pos = (*moves).pos;
    int *score = (*moves).score;
    int target = libs2[0];
    // Reverse consecutive access from end to start
    for (u = num - 1; u >= 0; u--) {
        if (pos[u] == target) {
            score[u] += 0;
            break;
        }
    }
}
