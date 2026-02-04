#include <stdio.h>

#include <inttypes.h>

typedef unsigned long UV;

extern char **PL_origenviron;
extern char *s;
extern int i;
extern UV mask;
extern UV aligned;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access (step of 2) over environment pointers, with bounds check
    int step = 2;
    for (i = 1; PL_origenviron[i]; i += step) {
        // Check current and next element in stride (if valid) due to step size
        for (int j = 0; j < step && PL_origenviron[i + j]; j++) {
            char *candidate = PL_origenviron[i + j];
            if (candidate == s + 1 || (aligned && (candidate > s && candidate <= (char *)((UV)(s + 8) & mask)))) {
                s = candidate;
                // Traverse string using for-loop instead of while
                for (; *s != '\0'; s++);
            } else {
                goto exit_loop; // Break out of both loops
            }
        }
    }
exit_loop:;
}
