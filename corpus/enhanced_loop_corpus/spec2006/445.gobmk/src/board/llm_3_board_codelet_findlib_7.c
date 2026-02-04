#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

struct string_data {
    int color;
    int size;
    int origin;
    int liberties;
    int libs[20];
    int neighbors;
    int neighborlist[160];
    int mark;
};


extern Intersection board[421];
extern struct string_data string[240];
extern int next_stone[400];
extern int ml[400];
extern int liberty_mark;
extern int maxlib;
extern int *libs;
extern int k;
extern int liberties;
extern int s;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via precomputed neighbor indices to simulate irregular/strided access patterns
    // Assume that neighborlist contains precomputed absolute positions around the current stone chain
    int idx, neighbor_idx;
    int *neighbor_ptr = &string[s].neighborlist[0];
    int neighbor_count = string[s].neighbors;

    for (k = 0, pos = string[s].origin; k < maxlib && k < liberties && pos != 0; pos = next_stone[pos]) {
        // Traverse indirect neighbor list derived from string's neighborhood data
        for (neighbor_idx = 0; neighbor_idx < neighbor_count && k < maxlib; neighbor_idx++) {
            idx = *(neighbor_ptr + neighbor_idx);  // Indirect access through neighborlist
            if (board[idx] == 0 && ml[idx] != liberty_mark) {
                libs[k++] = idx;
                ml[idx] = liberty_mark;
            }
        }
    }
}
