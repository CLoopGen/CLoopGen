#include <stdio.h>

#include <inttypes.h>

extern int max_pos;
extern int pos;
extern int *_o;
extern int *_i;
extern int *_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < max_pos; outer += 2) {
        for (pos = outer; pos < outer + 2 && pos < max_pos; pos++) {
            _o[pos] = _i[pos] + _j[pos];
        }
    }
}
