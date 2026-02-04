#include <stdio.h>

#include <inttypes.h>

extern int qsz;
extern char *base;
extern char c;
extern char *i;
extern char *j;
extern char *hi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access from both ends meeting in the middle
    // Simulates bidirectional traversal with mirrored indices
    char *low = base;
    char *high = base + qsz - 1;
    for (; low < high; ++low, --high) {
        c = *low;
        *low = *high;
        *high = c;
    }
    // Update original pointers to reflect final state (if needed by context)
    i = low;
    j = high;
    hi = base + qsz;
}
