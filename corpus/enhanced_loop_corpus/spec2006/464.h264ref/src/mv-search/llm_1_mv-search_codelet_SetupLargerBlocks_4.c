#include <stdio.h>

#include <inttypes.h>

extern int max_pos;
extern int pos;
extern int *_o;
extern int *_i;
extern int *_j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer, inner;
int chunk_size = 1;
int total = max_pos;

for (outer = 0; outer < total; outer += chunk_size) {
    for (inner = outer; inner < outer + chunk_size && inner < total; inner++) {
        pos = inner;
        _o[pos] = _i[pos] + _j[pos];
    }
}
}
