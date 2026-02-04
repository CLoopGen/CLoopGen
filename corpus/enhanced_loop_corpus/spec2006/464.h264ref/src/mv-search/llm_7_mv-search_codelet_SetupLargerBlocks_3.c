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
        _o[pos] = _i[pos] + _o[pos-1];
    }
    if (max_pos > 0) {
        _o[0] = _i[0] + _j[0];
    }
}
