#include <inttypes.h>

int i;
unsigned short *p;
unsigned short j;

static unsigned short data[131072]; // 256KB of data (131072 elements * 2 bytes)

void init_vars() {
    i = 0;
    j = 0;
    p = data;
    
    for (int idx = 0; idx < 131072; idx++) {
        data[idx] = (unsigned short)(idx * idx + 1);
    }
}

// Reset variables before calling loop to ensure correct state
void prepare_loop() {
    i = 2;
    j = 0;
}