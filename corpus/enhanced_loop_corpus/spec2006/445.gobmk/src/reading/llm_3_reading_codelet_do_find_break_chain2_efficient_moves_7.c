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
    int num = (*moves).num;
    int lib_val = libs[1];
    int index[50];
    for (int i = 0; i < num; i++) {
        index[i] = i;
    }
    for (u = 0; u < num; u++) {
        int idx = index[u]; // Indirect access via index array
        if ((*moves).pos[idx] == lib_val) {
            (*moves).score[idx] += 1;
            break;
        }
    }
}
