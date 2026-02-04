#include <stdio.h>

#include <inttypes.h>

extern int max_pos;
extern int pos;
extern int *_o;
extern int *_i;
extern int *_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access using index array
    for (pos = 0; pos < max_pos; pos++)
        _o[_i[pos]] = _i[_j[pos]] + _j[pos];  // Assuming _i contains valid indices for indirect access into _o and _j
}
