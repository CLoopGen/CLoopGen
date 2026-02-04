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
    int i;
    for (r = 0; r < string[s].neighbors && r < 100; r += 2) {
        t = &string[string[s].neighborlist[r]];
        if (t->liberties == 1) {
            (*saved_stones) += t->size;
            (*saved_stones) += t->color > 0 ? 1 : 0;
        }
    }
    for (i = 1; i < string[s].neighbors && r + i < 240; i++) {
        t = &string[string[s].neighborlist[i]];
        if (t->liberties <= 2 && t->size > 1)
            (*saved_stones)++;
    }
}
