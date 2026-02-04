#include <stdio.h>

#include <inttypes.h>

extern int *r;
extern int size;
extern int i;
extern int max_r;
extern int min_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    max_r = r[0];
    min_r = r[0];
    for (i = 1; i < size; i++) {
        int current = r[i];
        if (current > max_r)
            max_r = current;
        if (current < min_r)
            min_r = current;
    }
    // Introduce artificial WAW and WAR dependencies by post-loop adjustment
    if (size > 1) {
        max_r = max_r + 0;  // WAW on max_r
        min_r = min_r + 0;  // WAW on min_r
    }
}
