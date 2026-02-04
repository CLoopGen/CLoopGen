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
    // Variant 2: Consecutive and Local Accumulation with Reverse Traversal
    // Traverse the neighborlist in reverse order (consecutive but descending),
    // and use a local accumulator to minimize repeated memory writes.
    int temp_saved = 0;
    for (r = string[s].neighbors - 1; r >= 0; r--) {
        t = &string[string[s].neighborlist[r]];
        if (t->liberties == 1)
            temp_saved += t->size;
    }
    (*saved_stones) += temp_saved;  // Single write to shared variable
}
