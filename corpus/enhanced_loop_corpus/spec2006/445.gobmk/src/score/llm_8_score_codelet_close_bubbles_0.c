#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int gb[400];
extern int bubbles[400];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 400; ii += 2) {
    int idx = ii + 21;
    if (idx >= 421) break;
    if (!(board[idx] != 3) || gb[idx])
        continue;
    if (bubbles[idx] == 1)
        gb[idx] = 1;
    else if (bubbles[idx] == 2)
        gb[idx] = -1;
}
}
