#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int under_control[400];
extern int distance[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = 21;
    int limit = 400;
    for (pos = start; pos < limit; pos += 2) {
        if ((board[pos] ^ 3) == 0) {
            under_control[pos] = (distance[pos] != -1);
        }
    }
}
