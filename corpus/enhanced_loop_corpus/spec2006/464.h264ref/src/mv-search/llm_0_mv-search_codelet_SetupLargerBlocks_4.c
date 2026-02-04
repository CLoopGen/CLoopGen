#include <stdio.h>

#include <inttypes.h>

extern int max_pos;
extern int pos;
extern int *_o;
extern int *_i;
extern int *_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int pos1;
for (pos1 = 0; pos1 < max_pos; pos1++) {
    pos = pos1;
    _o[pos] = _i[pos] + _j[pos];
}
}
