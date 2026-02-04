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
    // Variant 2: Strided memory access — process neighbors in reverse order with stride of 2, then cover the rest
    int neighbors = string[s].neighbors;
    int start = neighbors - 1;

    // First pass: strided access (every second element backwards)
    for (r = start; r >= 0; r -= 2) {
        t = &string[string[s].neighborlist[r]];
        if (t->liberties == 1)
            (*saved_stones) += t->size;
    }

    // Second pass: fill in the stride gaps (odd indices if started from even, etc.)
    int second_start = (neighbors % 2 == 0) ? neighbors - 2 : neighbors - 1;
    for (r = second_start; r >= 1; r -= 2) {
        t = &string[string[s].neighborlist[r - 1]];
        if (t->liberties == 1)
            (*saved_stones) += t->size;
    }
}
