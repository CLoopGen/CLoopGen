#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int gb[400];
extern int bubbles[400];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated with arithmetic)
    int indices[400];
    int count = 0;
    for (int temp_ii = (19 + 2); temp_ii < (19 + 1) * (19 + 1); temp_ii++) {
        indices[count++] = temp_ii;
    }
    for (int idx = 0; idx < count; idx++) {
        ii = indices[idx];
        if (!(board[ii] != 3) || gb[ii])
            continue;
        if (bubbles[ii] == 1)
            gb[ii] = 1;
        if (bubbles[ii] == 2)
            gb[ii] = -1;
    }
}
