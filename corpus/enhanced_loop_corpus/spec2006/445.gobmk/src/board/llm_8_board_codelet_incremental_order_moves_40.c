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
    for (r = 0; r < string[s].neighbors && r < 160; r += 2) {
        if (r + 1 >= string[s].neighbors) break;
        t = &string[string[s].neighborlist[r]];
        if (t->liberties == 1)
            (*saved_stones) += t->size;
        t = &string[string[s].neighborlist[r + 1]];
        if (t->liberties == 1)
            (*saved_stones) += t->size;
    }
}
