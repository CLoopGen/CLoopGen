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
    int local_saved = *saved_stones;
    for (r = 0; r < string[s].neighbors; r++) {
        i = string[s].neighborlist[r];
        t = &string[i];
        t->mark = t->liberties;  // Introduce WAW dependency across iterations if mark is reused
        if (t->liberties == 1) {
            local_saved += t->size;
            t->mark++;  // Modify same location after read — creates WAR/WAW within loop iteration
        }
    }
    *saved_stones = local_saved;
}
