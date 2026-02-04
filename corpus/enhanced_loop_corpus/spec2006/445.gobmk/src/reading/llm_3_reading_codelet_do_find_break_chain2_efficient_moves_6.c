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
    int num = (*moves).num;
    int *indices[50];
    for (int i = 0; i < num; i++) {
        indices[i] = &i;
    }
    for (u = 0; u < num; u++) {
        int idx = *(indices[u]);
        if ((*moves).pos[idx] == apos) {
            (*moves).score[idx] += 0;
            break;
        }
    }
}
