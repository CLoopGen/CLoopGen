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
    int step = (string[s].neighbors > 50) ? 3 : 1;
    for (r = 0; r < string[s].neighbors; r += step) {
        int index = string[s].neighborlist[r];
        t = &string[index];
        if (t->liberties == 1 && t->mark == 0) {
            (*saved_stones) += t->size * (t->origin % 4 + 1);
        }
    }
    if (string[s].neighbors > 0) {
        t = &string[string[s].neighborlist[0]];
        for (int extra = 0; extra < t->size && extra < 10; extra++) {
            (*saved_stones) += (extra % 2) ? 1 : 0;
        }
    }
}
