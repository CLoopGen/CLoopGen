#include <stdio.h>

#include <inttypes.h>

extern int max_pos;
extern int pos;
extern int *_o;
extern int *_i;
extern int *_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (pos = 0; pos < max_pos; pos++) {
        temp = _i[pos] + _j[pos];  // Introduce temporary variable creating WAW and RAW dependencies within the loop body
        _o[pos] = temp;
    }
}
