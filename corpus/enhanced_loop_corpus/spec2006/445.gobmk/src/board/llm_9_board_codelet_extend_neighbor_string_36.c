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
    // Variant 2: Reduced trip count with stride and conditional skip, lowering overall operations
    int step = 1;
    if (string[s].neighbors > 80) {
        step = 3; // For large neighbor counts, process every third element only
    }
    for (k = 0; k < string[s].neighbors; k += step) {
        int target = string[s].neighborlist[k];
        string[target].mark = string_mark;
    }
}
