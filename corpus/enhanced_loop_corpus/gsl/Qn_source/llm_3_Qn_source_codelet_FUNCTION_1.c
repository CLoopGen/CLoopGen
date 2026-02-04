#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int *weight;
extern int i;
extern int j;
extern int jh;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via pointer arithmetic with offset indexing
    // Use pointers to traverse arrays with an effective indirect access pattern
    // Base pointers are offset by i, simulating more complex data structures or views
    int *l_ptr = left + 1;
    int *r_ptr = right + 1;
    for (i = 1; i < ni; ++i) {
        if (*(l_ptr++) <= *(r_ptr++)) {
            weight[j] = r_ptr[-1] - l_ptr[-1] + 1;
            jh = l_ptr[-1] + weight[j] / 2;
            ++j;
        }
    }
}
