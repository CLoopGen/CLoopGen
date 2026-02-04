#include <stdio.h>
#include <inttypes.h>

typedef short word;

#define LOOP_SIZE 13
#define DATA_SIZE (1 << 20)  // ~2MB of data to ensure loop takes ~0.01s due to memory traffic

static word x_data[DATA_SIZE];
static word xM_data[LOOP_SIZE];

word *x = x_data;
word *xM = xM_data;
int i = 0;
const word Mc = DATA_SIZE / 2;  // Ensure Mc + 3*i stays within bounds: Mc + 3*12 <= DATA_SIZE-1

void init_vars() {
    for (int j = 0; j < DATA_SIZE; j++) {
        x_data[j] = (word)(j & 0xFFFF);
    }
    for (int j = 0; j < LOOP_SIZE; j++) {
        xM_data[j] = 0;
    }
    i = 0;
}