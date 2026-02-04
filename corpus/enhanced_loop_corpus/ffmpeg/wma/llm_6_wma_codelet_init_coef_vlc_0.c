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
    for (j = 0; j < l; j++) {
        run_table[i + j] = j;
        level_table[i + j] = level;
        flevel_table[i + j] = (float)level;
    }
    i += l;
}
