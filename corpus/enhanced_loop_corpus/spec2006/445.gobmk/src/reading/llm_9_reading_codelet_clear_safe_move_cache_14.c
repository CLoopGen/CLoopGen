#include <stdio.h>

#include <inttypes.h>

extern int safe_move_cache_when[400][2];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = 21;
    int end = 400;
    int i, j;
    for (i = start; i < end; i++) {
        for (j = 0; j < 2; j++) {
            safe_move_cache_when[i][j] = -1 - (j % 2);
        }
    }
}
