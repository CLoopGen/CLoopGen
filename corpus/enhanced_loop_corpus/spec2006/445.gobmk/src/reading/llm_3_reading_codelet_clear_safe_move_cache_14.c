#include <stdio.h>

#include <inttypes.h>

extern int safe_move_cache_when[400][2];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 21; k < 400; k++) {
    int index = (k * 3) % 400; // Indirect access using a simple hash-like index
    safe_move_cache_when[index][0] = -1;
    safe_move_cache_when[index][1] = -1;
}
}
