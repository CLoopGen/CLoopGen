#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int replacement_map[400];
extern int from;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base = 19;
    int limit = (base + 1) * (base + 1);
    int offset = base + 2;
    for (pos = offset; pos < limit; pos++) {
        int rmap_val = replacement_map[pos];
        int from_val = from;
        if ((board[pos] != 3) && (rmap_val == from_val)) {
            replacement_map[pos] = replacement_map[from_val];
        }
    }
}
