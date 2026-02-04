#include <stdio.h>

#include <inttypes.h>

extern int safe_move_cache_when[400][2];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 1; i <= 20; i++) {
        for (k = 21; k < 400; k++) {
            safe_move_cache_when[k][0] = -1;
            safe_move_cache_when[k][1] = -1;
        }
    }
}
