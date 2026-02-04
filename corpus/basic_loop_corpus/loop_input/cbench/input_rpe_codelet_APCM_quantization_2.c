#include <stdio.h>
#include <inttypes.h>

typedef short word;

word *xM;
int i;
word xmax;
word temp;

static word xM_data[13]; // Size 13 to cover indices 0..12

void init_vars() {
    xM = xM_data;
    i = 0;
    xmax = 0;
    temp = 0;

    // Initialize xM_data with sample values to ensure defined behavior
    for (int idx = 0; idx < 13; idx++) {
        xM_data[idx] = (word)(idx * 1000);
    }
}