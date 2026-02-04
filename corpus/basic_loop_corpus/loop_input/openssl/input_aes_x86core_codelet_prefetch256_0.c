#include <stdint.h>

volatile unsigned long *t;
unsigned long sum;
int i;

#define DATA_SIZE (512 * 1024) // 512 KB of data

static unsigned long data[DATA_SIZE / sizeof(unsigned long)];

void init_vars() {
    for (int j = 0; j < (int)(DATA_SIZE / sizeof(unsigned long)); ++j) {
        data[j] = j ^ 0xDEADBEEF;
    }
    t = data;
}