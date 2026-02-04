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
    // Variant 2: Reduced effective trip count with increased per-iteration work via accumulation over blocks
    // Simulates lower loop frequency but higher computation density per iteration
    int step = 3;
    int local_saved = 0;
    for (r = 0; r < string[s].neighbors; r += step) {
        for (int k = 0; k < step && (r + k) < string[s].neighbors; k++) {
            t = &string[string[s].neighborlist[r + k]];
            if (t->liberties <= 2) {  // Slightly modified condition to increase relevance
                local_saved += t->size * (t->mark != 0 ? 2 : 1); // Additional arithmetic and use of another field
            }
        }
    }
    (*saved_stones) += local_saved;
}
