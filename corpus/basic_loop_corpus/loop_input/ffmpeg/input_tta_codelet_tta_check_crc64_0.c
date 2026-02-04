#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint64_t crc;
uint64_t poly;
int i;

void init_vars() {
    crc = 0xABCDEF1234567890ULL;
    poly = 0x9B00000000000000ULL;
    i = 0;
}