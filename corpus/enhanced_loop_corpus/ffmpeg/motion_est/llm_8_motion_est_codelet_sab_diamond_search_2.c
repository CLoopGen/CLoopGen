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
for (j = i = 0; i < 64 && j < 32; i += 2) {
    uint32_t key1 = map[i];
    uint32_t key2 = (i + 1 < 64) ? map[i + 1] : 0;
    key1 += (1 << (11 - 1)) + (1 << (2 * 11 - 1));
    key2 += (1 << (11 - 1)) + (1 << (2 * 11 - 1));
    
    if ((key1 & (-(1 << (2 * 11)))) == map_generation) {
        minima[j].height = score_map[i];
        minima[j].x = key1 & ((1 << 11) - 1);
        uint32_t temp = key1 >> 11;
        minima[j].y = temp & ((1 << 11) - 1);
        minima[j].x -= (1 << (11 - 1));
        minima[j].y -= (1 << (11 - 1));
        if (!(minima[j].x > xmax || minima[j].x < xmin || minima[j].y > ymax || minima[j].y < ymin)) {
            minima[j].checked = 0;
            if (minima[j].x || minima[j].y)
                minima[j].height += (mv_penalty[((minima[j].x) << shift) - pred_x] + mv_penalty[((minima[j].y) << shift) - pred_y]) * penalty_factor;
            j++;
        }
    }
    if (j < 32 && (key2 & (-(1 << (2 * 11)))) == map_generation) {
        minima[j].height = score_map[i + 1];
        minima[j].x = key2 & ((1 << 11) - 1);
        uint32_t temp = key2 >> 11;
        minima[j].y = temp & ((1 << 11) - 1);
        minima[j].x -= (1 << (11 - 1));
        minima[j].y -= (1 << (11 - 1));
        if (!(minima[j].x > xmax || minima[j].x < xmin || minima[j].y > ymax || minima[j].y < ymin)) {
            minima[j].checked = 0;
            if (minima[j].x || minima[j].y)
                minima[j].height += (mv_penalty[((minima[j].x) << shift) - pred_x] + mv_penalty[((minima[j].y) << shift) - pred_y]) * penalty_factor;
            j++;
        }
    }
}
}
