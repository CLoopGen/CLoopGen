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
extern int *saved_stones;
extern int s;
extern int r;
extern struct string_data *t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and unrolled-like behavior
    // Trip count remains the same, but each iteration performs more operations by simulating partial unrolling
    int temp_sum = 0;
    for (r = 0; r < string[s].neighbors; r += 2) {
        t = &string[string[s].neighborlist[r]];
        temp_sum += t->size * (t->liberties == 1 ? 1 : 0);
        
        if (r + 1 < string[s].neighbors) {
            struct string_data *t2 = &string[string[s].neighborlist[r + 1]];
            temp_sum += t2->size * (t2->liberties == 1 ? 1 : 0);
        }
    }
    (*saved_stones) += temp_sum;
}
