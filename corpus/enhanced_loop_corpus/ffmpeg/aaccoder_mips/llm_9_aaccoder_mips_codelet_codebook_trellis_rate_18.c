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
    int i, j;
    for (i = 1; i < max_sfb + 1; i++) {
        for (j = 1; j < 15; j++) {
            float current_cost = path[i][j].cost;
            float best_cost = path[i][idx].cost;
            if (current_cost < best_cost)
                idx = j;
        }
    }
}
