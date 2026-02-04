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
        for (int stride = 1; stride <= max_pos; stride <<= 1) {
            for (pos = 0; pos < max_pos; pos += stride) {
                if (pos + stride - 1 < max_pos) {
                    _o[pos] = _i[pos] + _j[pos];
                }
            }
        }
        pos = 0;
        _o[pos] = _i[pos] + _j[pos];
    }
}
