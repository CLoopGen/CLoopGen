#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern struct reading_moves *moves;
extern int libs[2];
extern int u;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_score = 0;
    int found_index = -1;
    for (u = 0; u < (*moves).num; u++) {
        if ((*moves).pos[u] == libs[1]) {
            found_index = u;
            temp_score = (*moves).score[u] + 1;
            break;
        }
    }
    if (found_index != -1) {
        (*moves).score[found_index] = temp_score;
    }
}
