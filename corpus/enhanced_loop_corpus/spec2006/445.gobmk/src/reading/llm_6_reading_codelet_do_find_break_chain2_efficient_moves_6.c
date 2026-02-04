#include <stdio.h>

#include <inttypes.h>

struct reading_moves {
    int pos[50];
    int score[50];
    int num;
};


extern struct reading_moves *moves;
extern int apos;
extern int u;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_score = 0;
    for (u = 0; u < (*moves).num; u++) {
        if ((*moves).pos[u] == apos) {
            temp_score = (*moves).score[u];
            break;
        }
    }
    // Introduce a WAR dependency by writing after potential read
    for (u = 0; u < (*moves).num; u++) {
        if ((*moves).pos[u] == apos) {
            (*moves).score[u] = temp_score;
            break;
        }
    }
}
