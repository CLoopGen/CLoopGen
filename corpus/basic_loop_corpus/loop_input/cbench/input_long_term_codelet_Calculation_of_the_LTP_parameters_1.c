#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef short word;

word *d;
int k;
word wt[40];
word scal;

void init_vars() {
    // Allocate d with 40 elements to match loop bounds [0, 39]
    d = (word*)aligned_alloc(sizeof(word), 40 * sizeof(word));
    if (!d) exit(1);

    // Initialize scal to a non-zero shift value (e.g., 1) to ensure defined behavior
    scal = 1;

    // Initialize d with sample data (all 1s for simplicity)
    for (int i = 0; i < 40; i++) {
        d[i] = (word)(i + 1);
    }

    // Optionally initialize wt to zero before loop
    memset(wt, 0, sizeof(wt));
}