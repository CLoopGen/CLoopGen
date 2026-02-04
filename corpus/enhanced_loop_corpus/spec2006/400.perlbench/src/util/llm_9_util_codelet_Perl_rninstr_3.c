#include <stdio.h>

#include <inttypes.h>

extern  char *big;
extern  char *little;
extern  char *s;
extern  char *x;
extern  char *littleend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced arithmetic frequency with conditional skipping and increased trip count
    // Simulates sparse comparison by stepping every other element, then compensating
    char *local_x = big + 2;
    char *local_s = little;
    int step = 1;
    int offset = 0;

    for (; local_s < littleend; ++local_s, ++local_x, ++offset) {
        if (offset % (step + 1) == 0) {  // Only compare on certain iterations
            if (*local_s != *local_x) {
                break;
            }
        }
    }
    s = local_s;
    x = local_x;
}
