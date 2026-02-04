#include <stdio.h>

#include <inttypes.h>

extern int max_pos;
extern int pos;
extern int *_o;
extern int *_i;
extern int *_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pos = 0; pos < max_pos * 2; pos++) {
        int idx = pos / 2;
        if (idx < max_pos) {
            _o[idx] += (_i[idx] + _j[idx]) * (_i[idx] - _j[idx]); // Equivalent to i^2 - j^2
        }
    }
}
