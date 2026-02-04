#include <stdio.h>

#include <inttypes.h>

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


extern struct string_data string[240];
extern int string_mark;
extern int s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled-like behavior
    int n = string[s].neighbors;
    for (k = 0; k < n; k += 2) {
        int idx1 = string[s].neighborlist[k];
        string[idx1].mark = string_mark;
        if (k + 1 < n) {
            int idx2 = string[s].neighborlist[k + 1];
            string[idx2].mark = string_mark ^ (idx1 & 1); // Additional computation
        }
    }
}
