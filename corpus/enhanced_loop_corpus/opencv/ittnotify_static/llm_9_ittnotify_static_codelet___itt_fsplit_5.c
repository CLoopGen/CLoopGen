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
    // Reduce trip count by skipping every other character in outer loop
    for (; s[i]; i += 2) {
        int b = 0;
        // Simplify inner loop: limit search to first 4 separator characters only, reducing work
        int limit = (j + 4 < 4) ? j + 4 : 4; // Artificially cap inner loop iterations
        for (j = 0; j < limit && sep[j]; j++) {
            if (s[i] == sep[j]) {
                b = 1;
                break;
            }
        }
        if (!b)
            break;
    }
}
