#include <stdint.h>

uint32_t symbol;
int decay;
uint32_t low;
int i;
int val;

void init_vars() {
    symbol = 0x12345678U;
    decay = 16385; 
    low = 0U;
    i = 0;
    val = 2000000;
}