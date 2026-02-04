#include <inttypes.h>

long num[5] = {0};
int i = 0;
unsigned long work = 0;
unsigned long carry = 0;
unsigned long scale = 1UL << 20;

void init_vars() {
    for (int j = 0; j < 5; j++) {
        num[j] = (long)(j + 1) * 1000;
    }
    carry = 0x12345678UL;
    scale = 0xABCDEF01UL;
}