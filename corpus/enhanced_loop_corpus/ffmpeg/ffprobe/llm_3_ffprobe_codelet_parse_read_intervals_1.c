#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern char *p;
extern char *spec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Instead of direct sequential access, we simulate indirect access by using an offset list.
    // Here, we create a static stride pattern that jumps forward by 1 or 2 based on position.
    int i;
    char *temp_p = spec;
    n = 0;
    for (i = 0; temp_p[i]; ) {
        if (temp_p[i] == ',') {
            n++;
        }
        // Simulate irregular (indirect-like) access: alternate between step 1 and 2
        i += (i % 2 == 0) ? 1 : 2;
    }
}
