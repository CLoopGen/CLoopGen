#include <stdio.h>

#include <inttypes.h>

extern int max_pos;
extern int pos;
extern int *_o;
extern int *_i;
extern int *_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pos = 0; pos < max_pos; pos++) {
        int temp_sum = _i[pos] + _j[pos];
        int temp_sq = temp_sum * temp_sum;
        _o[pos] = temp_sq + temp_sum;
    }
}
