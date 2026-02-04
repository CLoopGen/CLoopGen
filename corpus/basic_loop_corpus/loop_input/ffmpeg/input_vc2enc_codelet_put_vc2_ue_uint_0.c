#include <stdint.h>
#include <stddef.h>

uint32_t val = 0x80000000;
int i;
int bits = 32;
unsigned int topbit = 0x80000000;
uint64_t pbits;

void init_vars() {
    val = 0x80000000;
    bits = 32;
    topbit = 0x80000000;
    pbits = 0;
}