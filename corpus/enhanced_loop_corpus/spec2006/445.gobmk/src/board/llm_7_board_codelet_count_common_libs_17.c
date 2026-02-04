#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int ml[400];
extern int liberty_mark;
extern int *libs1;
extern int liberties2;
extern int commonlibs;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count with stride and simplified condition
    // Only process every second element to reduce work, but keep same control flow structure
    int k;
    for (k = 0; k < liberties2; k += 2) {  // Half the effective iterations
        Intersection pos = board[libs1[k]];
        if (!(pos == 0 && ml[libs1[k]] != liberty_mark))
            commonlibs++;
    }
    // Optional compensation: if original count matters, we could scale commonlibs,
    // but here we assume mutation is acceptable as reduced workload.
}
