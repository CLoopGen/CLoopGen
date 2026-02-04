#include <stdio.h>

#include <inttypes.h>

extern int max_pos;
extern int pos;
extern int *_o;
extern int *_i;
extern int *_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (max_pos > 0) {
        pos = 0;
        for (int step = 0; step < max_pos; step += 16) {
            for (pos = step; pos < step + 16 && pos < max_pos; pos++) {
                _o[pos] = _i[pos] + _j[pos];
            }
        }
    }
}
