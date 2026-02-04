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
    int temp_x = key & ((1 << 11) - 1);
    key >>= 11;
    int temp_y = key & ((1 << 11) - 1);
    temp_x -= (1 << (11 - 1));
    temp_y -= (1 << (11 - 1));
    if (temp_x > xmax || temp_x < xmin || temp_y > ymax || temp_y < ymin)
        continue;
    minima[j].height = score_map[i];
    minima[j].x = temp_x;
    minima[j].y = temp_y;
    minima[j].checked = 0;
    if (temp_x || temp_y)
        minima[j].height += (mv_penalty[(temp_x << shift) - pred_x] + mv_penalty[(temp_y << shift) - pred_y]) * penalty_factor;
    j++;
}
}
