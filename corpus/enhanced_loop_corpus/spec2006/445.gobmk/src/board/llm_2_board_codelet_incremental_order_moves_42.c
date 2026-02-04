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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing neighborlist sequentially, access it with a stride of 2,
    // wrapping around if necessary to ensure all elements are eventually covered.
    int n = string[s].neighbors;
    for (r = 0; r < n; r++) {
        int idx = (r * 2) % n;  // Strided access: every second element
        t = &string[string[s].neighborlist[idx]];
        if (t->liberties == 1)
            (*saved_stones) += t->size;
    }
}
