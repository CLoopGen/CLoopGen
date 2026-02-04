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
    int limit = string[s].neighbors * 2;
    for (r = 0; r < limit; r++) {
        int idx = r / 2;
        if (idx >= string[s].neighbors) continue;
        t = &string[string[s].neighborlist[idx]];
        if (t->liberties == 1 && r % 2 == 0)
            (*saved_stones) += t->size * (t->color + 1);
    }
}
