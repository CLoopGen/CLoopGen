#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int replacement_map[400];
extern int from;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = 21;
    int step = 2;
    int limit = (19 + 1) * (19 + 1);
    for (pos = start; pos < limit; pos += step) {
        if ((board[pos] != 3) && replacement_map[pos] == from)
            replacement_map[pos] = replacement_map[from];
    }
}
