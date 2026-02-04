#include <stdio.h>

#include <inttypes.h>

extern int *regmove_bb_head;
extern int old_max_uid;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with index remapping
    int start = 0;
    int end = old_max_uid;
    for (i = start; i <= end; i++)
        regmove_bb_head[end - i] = -1;  // Access in reverse order consecutively
}
