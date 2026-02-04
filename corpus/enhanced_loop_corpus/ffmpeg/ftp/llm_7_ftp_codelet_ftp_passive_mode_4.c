#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *res;
extern char *start;
extern char *end;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset_start = -1;
    ptrdiff_t offset_end = -1;
    for (i = 0; res[i]; ++i) {
        // Remove direct data dependency on 'start' until after loop
        if (res[i] == '(') {
            offset_start = i + 1; // Store offset instead of raw pointer (eliminates RAW on 'res' in pointer calc)
        } else if (res[i] == ')') {
            offset_end = i;
            break;
        }
    }
    // Resolve pointers outside the loop to remove loop-carried dependence on global pointers
    if (offset_start != -1 && offset_end != -1) {
        start = res + offset_start;
        end = res + offset_end;
    }
}
