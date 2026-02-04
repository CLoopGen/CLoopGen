#include <stdio.h>

#include <inttypes.h>

extern int max_pos;
extern int pos;
extern int *_o;
extern int *_i;
extern int *_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_pos;
    if (max_pos > 0) {
        for (temp_pos = 0; temp_pos < max_pos; temp_pos++) {
            pos = temp_pos;
            _o[pos] = _i[pos] + _j[pos];
        }
    } else {
        pos = 0;
    }
}
