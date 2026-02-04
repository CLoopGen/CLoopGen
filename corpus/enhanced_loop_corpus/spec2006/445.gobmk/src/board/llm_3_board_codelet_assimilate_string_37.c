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
extern int ml[400];
extern int liberty_mark;
extern int s;
extern int k;
extern int s2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather) access pattern using an index map
    // Precompute valid indices and access through an indirect index array (simulated statically)
    int valid_indices[20];
    int count = 0;
    int i;

    // First pass: gather valid liberty positions
    for (k = 0; k < string[s2].liberties; k++) {
        int pos2 = string[s2].libs[k];
        if ((board[pos2] == 0 && ml[pos2] != liberty_mark)) {
            valid_indices[count++] = pos2;
        }
    }

    // Second pass: update the libs array using indirect access
    for (i = 0; i < count && string[s].liberties + i < 20; i++) {
        int pos2 = valid_indices[i];
        string[s].libs[string[s].liberties + i] = pos2;
        ml[pos2] = liberty_mark;
    }
    string[s].liberties += count;
}
