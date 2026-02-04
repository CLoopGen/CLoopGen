#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int replacement_map[400];
extern int from;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = 0; depth1 < 2; depth1++) {
        for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
            if ((board[pos] != 3) && replacement_map[pos] == from)
                replacement_map[pos] = replacement_map[from];
        }
    }
}
