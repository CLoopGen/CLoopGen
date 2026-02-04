#include <stdio.h>

#include <inttypes.h>

extern int max_pos;
extern int pos;
extern int *_o;
extern int *_i;
extern int *_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (pos = 0; pos < max_pos; pos++) {
        temp = _i[pos] + _j[pos];
        _o[pos] = temp;
    }
}
