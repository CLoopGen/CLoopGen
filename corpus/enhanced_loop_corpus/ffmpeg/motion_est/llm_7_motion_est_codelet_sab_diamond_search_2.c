#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Minima {
    int height;
    int x;
    int y;
    int checked;
} Minima;

extern  int penalty_factor;
extern Minima minima[64];
extern int i;
extern int j;
extern __attribute__((unused)) uint32_t * score_map;
extern __attribute__((unused))  int xmin;
extern __attribute__((unused))  int ymin;
extern __attribute__((unused))  int xmax;
extern __attribute__((unused))  int ymax;
extern uint8_t *mv_penalty;
extern  int pred_x;
extern  int pred_y;
extern uint32_t *map;
extern  int shift;
extern unsigned int map_generation;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int local_j = 0;
for (i = 0; i < 64; i++) {
    uint32_t key = map[i];
    key += (1 << (10)) + (1 << (21)); // Precomputed shifts for clarity and dependency isolation
    if ((key & 0xFFE00000) != map_generation) // Explicit mask instead of negated shift
        continue;
    int raw_x = key & 0x7FF;
    int raw_y = (key >> 11) & 0x7FF;
    int final_x = raw_x - (1 << 10);
    int final_y = raw_y - (1 << 10);
    uint32_t score = score_map[i];
    if (final_x > xmax || final_x < xmin || final_y > ymax || final_y < ymin) {
        // No write to minima, so no WAW or WAR on minima[j]
    } else {
        // Introduce artificial dependence: current height depends on previous valid minimum
        if (local_j > 0)
            score += minima[local_j - 1].height >> 10; // RAW dependence across iterations
        minima[local_j].height = score;
        minima[local_j].x = final_x;
        minima[local_j].y = final_y;
        minima[local_j].checked = 0;
        if (final_x || final_y) {
            int px = (final_x << shift) - pred_x;
            int py = (final_y << shift) - pred_y;
            // Clamp access to mv_penalty bounds (assuming small shift, e.g., shift=1)
            px = (px < 0) ? 0 : px;
            py = (py < 0) ? 0 : py;
            minima[local_j].height += (mv_penalty[px] + mv_penalty[py]) * penalty_factor;
        }
        local_j++;
    }
}
j = local_j; // Update global j after loop
}
