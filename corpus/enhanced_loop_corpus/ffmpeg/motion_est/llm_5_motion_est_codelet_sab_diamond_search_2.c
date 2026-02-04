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
        int valid_generation = ((key & (-(1 << (2 * 11)))) == map_generation);
        int x_val = (key & ((1 << 11) - 1)) - (1 << (11 - 1));
        int y_val = ((key >> 11) & ((1 << 11) - 1)) - (1 << (11 - 1));
        int in_bounds = (x_val <= xmax && x_val >= xmin && y_val <= ymax && y_val >= ymin);
        
        if (valid_generation && in_bounds) {
            minima[j].height = score_map[i];
            minima[j].x = x_val;
            minima[j].y = y_val;
            minima[j].checked = 0;
            
            if (minima[j].x || minima[j].y) {
                minima[j].height += (mv_penalty[(minima[j].x << shift) - pred_x] + 
                                     mv_penalty[(minima[j].y << shift) - pred_y]) * penalty_factor;
            }
            j++;
        }
    }
}
