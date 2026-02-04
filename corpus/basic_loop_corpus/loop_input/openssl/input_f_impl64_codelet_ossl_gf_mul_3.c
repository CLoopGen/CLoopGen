#include <stdint.h>
#include <string.h>

uint64_t *a;
uint64_t *b;
uint64_t aa[4];
uint64_t bb[4];
uint64_t bbb[4];
unsigned int i;

static uint64_t a_data[8];
static uint64_t b_data[8];

void init_vars() {
    a = a_data;
    b = b_data;
    for (int j = 0; j < 8; j++) {
        a[j] = j + 1;
        b[j] = (j + 1) * 2;
    }
}