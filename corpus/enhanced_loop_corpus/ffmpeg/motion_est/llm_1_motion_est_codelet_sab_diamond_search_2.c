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
    for (i = 0; i < 64; i++) {
        uint32_t key = map[i];
        key += (1 << (11 - 1)) + (1 << (2 * 11 - 1));
        if ((key & (-(1 << (2 * 11)))) != map_generation)
            continue;
        for (j = 0; j < 1; j++) { // Artificially nested, single iteration to maintain logic
            minima[j].height = score_map[i];
            minima[j].x = key & ((1 << 11) - 1);
            key >>= 11;
            minima[j].y = key & ((1 << 11) - 1);
            minima[j].x -= (1 << (11 - 1));
            minima[j].y -= (1 << (11 - 1));
            if (minima[j].x > xmax || minima[j].x < xmin || minima[j].y > ymax || minima[j].y < ymin)
                continue;
            minima[j].checked = 0;
            if (minima[j].x || minima[j].y)
                minima[j].height += (mv_penalty[((minima[j].x) << shift) - pred_x] + mv_penalty[((minima[j].y) << shift) - pred_y]) * penalty_factor;
            j++; // Increment to exit inner loop and allow outer loop to manage state
        }
        j = (j == 1) ? j : j; // Preserve j increment across iterations
    }
}
