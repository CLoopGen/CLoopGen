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
        int temp1 = _i[pos] + _j[pos];
        int temp2 = temp1 * temp1;
        int temp3 = temp2 - temp1;
        _o[pos] = temp3 + (temp1 >> 1);
    }
}
