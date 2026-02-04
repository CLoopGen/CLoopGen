#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct TrellisBandCodingPath {
    int prev_idx;
    float cost;
    int run;
} TrellisBandCodingPath;

extern TrellisBandCodingPath path[120][15];
extern int cb;
extern  int max_sfb;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_idx = idx;
    for (cb = 1; cb < 15; cb++) {
        float current_cost = path[max_sfb][cb].cost;
        float best_cost = path[max_sfb][temp_idx].cost;
        if (current_cost < best_cost)
            temp_idx = cb;
    }
    idx = temp_idx;
}
