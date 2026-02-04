#include <stdio.h>

#include <inttypes.h>

extern int max_pos;
extern int pos;
extern int *_o;
extern int *_i;
extern int *_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Order Access (traverse arrays from end to beginning)
    for (pos = max_pos - 1; pos >= 0; pos--)
        _o[pos] = _i[pos] + _j[pos];
}
