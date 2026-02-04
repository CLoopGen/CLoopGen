#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define STATE_SIZE 625
#define DATA_SIZE (1 << 20)  // 1MB of data for ~0.01 sec runtime estimate

unsigned int state[625];
unsigned int *p0;
unsigned int *p2;
unsigned int *pM;
unsigned int s0;
unsigned int s1;
int j;

static unsigned int data_buffer[DATA_SIZE / sizeof(unsigned int)];

void init_vars() {
    // Initialize state array with non-zero values
    for (int i = 0; i < STATE_SIZE; i++) {
        state[i] = 1812433253U * (i + 1) + i;
    }

    // Allocate and initialize working buffers
    p0 = data_buffer;
    p2 = data_buffer + 1;
    
    // Ensure pM starts at beginning of state
    pM = state;
    
    // Initialize scalar values
    s0 = state[0];
    s1 = state[1];
    j = 397;
}