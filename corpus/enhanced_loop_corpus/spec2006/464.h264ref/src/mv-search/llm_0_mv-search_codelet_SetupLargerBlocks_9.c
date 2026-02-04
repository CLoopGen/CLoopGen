#include <stdio.h>

#include <inttypes.h>

extern int max_pos;
extern int pos;
extern int *_o;
extern int *_i;
extern int *_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_pos;
    int inner_pos;
    for (outer_pos = 0; outer_pos < max_pos; outer_pos += 2) {
        for (inner_pos = 0; inner_pos < 2 && (outer_pos + inner_pos) < max_pos; inner_pos++) {
            pos = outer_pos + inner_pos;
            _o[pos] = _i[pos] + _j[pos];
        }
    }
}
