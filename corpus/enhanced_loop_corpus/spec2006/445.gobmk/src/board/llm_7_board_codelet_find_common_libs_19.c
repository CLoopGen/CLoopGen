#include <stdio.h>

#include <inttypes.h>

extern int ml[400];
extern int liberty_mark;
extern int *libs1;
extern int liberties1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int local_mark = liberty_mark; // Eliminate potential loop-carried dependency by using local copy
    for (k = 0; k < liberties1; k++) {
        int idx = libs1[k];
        ml[idx] = local_mark; // Remove write dependency on shared liberty_mark (eliminate WAR/WAW if liberty_mark is used elsewhere)
    }
    // No mutation to shared state; all writes use invariant value from entry
}
