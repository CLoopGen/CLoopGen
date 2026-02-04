#include <stdint.h>

typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

int64_t a;
AVInteger out;
int i;

void init_vars() {
    a = 0x123456789ABCDEF0ULL;
    i = 0;
}