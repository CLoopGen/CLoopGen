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
    for (int temp_r = 0; temp_r < string[s].neighbors; temp_r++) {
        r = temp_r;
        t = &string[string[s].neighborlist[r]];
        if (t->liberties == 1) {
            (*saved_stones) += t->size;
        }
    }
}
