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
    for (j = i = 0; i < 64 && j < 64; i++) {
        uint32_t key = map[i];
        key += (1 << (11 - 1)) + (1 << (2 * 11 - 1));
        if ((key & (-(1 << (2 * 11)))) != map_generation)
            continue;
        int idx = i; // Direct consecutive access to score_map and map
        minima[j].height = score_map[idx];
        minima[j].x = key & ((1 << 11) - 1);
        key >>= 11;
        minima[j].y = key & ((1 << 11) - 1);
        minima[j].x -= (1 << (11 - 1));
        minima[j].y -= (1 << (11 - 1));
        if (minima[j].x > xmax || minima[j].x < xmin || minima[j].y > ymax || minima[j].y < ymin)
            continue;
        minima[j].checked = 0;
        if (minima[j].x || minima[j].y) {
            int mx = (minima[j].x) << shift;
            int my = (minima[j].y) << shift;
            minima[j].height += (mv_penalty[mx - pred_x] + mv_penalty[my - pred_y]) * penalty_factor;
        }
        j++;
    }
}
