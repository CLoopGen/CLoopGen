#include <stdio.h>

#include <inttypes.h>

extern int max_pos;
extern int pos;
extern int *_o;
extern int *_i;
extern int *_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (pos = 0; pos < max_pos; pos += 2) {
        if (pos + 1 < max_pos) {
            _o[pos]     = _i[pos]     + _j[pos];
            _o[pos + 1] = _i[pos + 1] + _j[pos + 1];
        } else {
            _o[pos] = _i[pos] + _j[pos];
        }
    }
}
