#include <inttypes.h>

#define DATA_SIZE 131072  // 128 KB

signed char *r;
uint8_t *a;
int i;

static signed char r_storage[DATA_SIZE];
static uint8_t a_storage[DATA_SIZE / 8];

void init_vars() {
    r = r_storage;
    a = a_storage;
    for (i = 0; i < DATA_SIZE / 8; ++i) {
        a[i] = (uint8_t)(i ^ (i >> 8));
    }
}