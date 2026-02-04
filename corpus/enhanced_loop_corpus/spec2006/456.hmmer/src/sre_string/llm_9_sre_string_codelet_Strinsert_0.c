#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char c;
extern int pos;
extern char oldc;
extern char *s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count using stride control and simplified data flow
    int step = 1 + ((pos >> 2) & 1); // Dynamic step size based on pos, either 1 or 2
    for (s = s1 + pos; c && (s - s1) < 1024; s += step) { // Bound trip count and use variable stride
        oldc = *s;
        *s = c;
        c = oldc;
    }
}
