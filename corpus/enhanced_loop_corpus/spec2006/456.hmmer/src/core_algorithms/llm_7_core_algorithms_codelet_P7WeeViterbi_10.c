#include <stdio.h>

#include <inttypes.h>

extern int *kassign;
extern char *tassign;
extern int s1;
extern int s2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = s2;
    for (; i >= s1; i -= 2) {
        // Eliminate loop-carried dependency by unrolling and making independent writes
        kassign[i] = 1;
        tassign[i] = 5;
        if (i - 1 >= s1) {
            kassign[i - 1] = 1;
            tassign[i - 1] = 5;
        }
    }
    // Handle odd count with cleanup if needed, but mutation focuses on main loop structure
    // This version reduces loop iterations and removes sequential dependency across iterations
}
