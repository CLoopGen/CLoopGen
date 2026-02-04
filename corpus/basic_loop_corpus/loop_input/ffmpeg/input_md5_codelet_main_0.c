#include <stdint.h>
#include <string.h>

int i;
volatile uint8_t in[1000];

void init_vars() {
    i = 0;
    memset((void*)in, 0, sizeof(in));
}