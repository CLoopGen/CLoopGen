#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *run_table;
extern uint16_t *level_table;
extern float *flevel_table;
extern int i;
extern int l;
extern int j;
extern int level;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (l > 0) {
    for (j = 0; j < l; j += 2) {
        run_table[i] = j;
        level_table[i] = level;
        flevel_table[i] = level;
        i++;
        if (j + 1 < l) {
            run_table[i] = j + 1;
            level_table[i] = level;
            flevel_table[i] = level;
            i++;
        }
    }
}
}
