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
    int i;
    for (i = 0; i < (*moves).num && i < 100; i++) {
        if ((*moves).pos[i] == libs[0] || (*moves).pos[i] == libs[1]) {
            (*moves).score[i] += 2;
        }
    }
}
