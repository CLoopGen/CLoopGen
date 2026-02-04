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
        for (int stride = 1; stride <= max_pos; stride *= 2) {
            for (pos = 0; pos < max_pos; pos += stride) {
                if (pos + stride / 2 < max_pos) {
                    int mid = pos + stride / 2;
                    _o[mid] = _i[mid] + _j[mid];
                }
                _o[pos] = _i[pos] + _j[pos];
            }
        }
    }
}
