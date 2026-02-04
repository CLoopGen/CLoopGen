#include <stdint.h>
#include <stddef.h>

uint32_t x[128];
uint32_t th[2];
int i;
int k;
int a;
int z;
int rp;
int e2;

void init_vars() {
    for (int idx = 0; idx < 128; idx++) {
        x[idx] = (uint32_t)(0x80000000U | (idx * 7919) % 100000000);
    }
    th[0] = 50000000;
    th[1] = 25000000;
    i = 0;
    k = 0;
    a = 0;
    z = 64;
    rp = 18;
    e2 = 0;
}