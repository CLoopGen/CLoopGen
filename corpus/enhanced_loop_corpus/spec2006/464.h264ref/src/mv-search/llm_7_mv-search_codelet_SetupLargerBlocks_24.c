#include <stdio.h>

#include <inttypes.h>

extern int max_pos;
extern int pos;
extern int *_o;
extern int *_i;
extern int *_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pos = 1; pos < max_pos; pos++) {
        // Introduce loop-carried RAW dependency: current iteration depends on previous output
        _o[pos] = _i[pos] + _j[pos] + _o[pos - 1];
    }
    if (max_pos > 0) {
        _o[0] = _i[0] + _j[0];  // Initialize first element without dependency
    }
}
