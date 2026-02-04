#include <stdio.h>

#include <inttypes.h>

extern int safe_move_cache_when[400][2];
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = (19 + 2); k < (19 + 1) * (19 + 1); k++) {
    safe_move_cache_when[k][0] = -1;
    safe_move_cache_when[k][1] = -1;
}

}
