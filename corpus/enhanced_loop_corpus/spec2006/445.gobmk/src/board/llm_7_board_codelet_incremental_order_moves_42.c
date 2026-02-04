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
    int local_saved = *saved_stones;
    for (r = 0; r < string[s].neighbors; r++) {
        struct string_data *t_local = &string[string[s].neighborlist[r]];
        t = t_local;
        if (t_local->liberties == 1) {
            local_saved += t_local->size;
            t_local->mark = 1; // Introduce WAW dependency on mark field, loop-carried via memory
        }
    }
    *saved_stones = local_saved;
}
