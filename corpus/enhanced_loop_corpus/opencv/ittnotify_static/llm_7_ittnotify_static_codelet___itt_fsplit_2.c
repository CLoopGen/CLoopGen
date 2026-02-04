#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; s[i]; i++) {
        int found = 0;
        // Eliminate loop-carried dependency on 'b' by using a different control structure
        // and reordering evaluation using immediate conditional logic.
        for (j = 0; sep[j] && !found; j++) {
            found = (s[i] == sep[j]);  // Direct assignment removes intermediate write-read chain
        }
        if (!found) {
            break;
        }
        // Artificially introduce a RAW dependency: use i in computation before potential next write
        volatile int dummy = i;  // Enforce read-after-write: i must be written before this read
        (void)dummy;
    }
}
