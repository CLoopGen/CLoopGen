#include <stdio.h>

#include <inttypes.h>

extern int ml[400];
extern int liberty_mark;
extern int *libs1;
extern int liberties1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with stride optimization and minimal operations
    for (k = 0; k < liberties1; k += 4) {
        ml[libs1[k]] = liberty_mark;
        if (k + 1 < liberties1) ml[libs1[k + 1]] = liberty_mark;
        if (k + 2 < liberties1) ml[libs1[k + 2]] = liberty_mark;
        if (k + 3 < liberties1) ml[libs1[k + 3]] = liberty_mark;
    }
}
