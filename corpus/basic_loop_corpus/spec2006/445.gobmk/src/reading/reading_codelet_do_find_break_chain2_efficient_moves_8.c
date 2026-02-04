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
for (u = 0; u < (*moves).num; u++)
    if ((*moves).pos[u] == (libs[0])) {
        (*moves).score[u] += 1;
        break;
    }

}
