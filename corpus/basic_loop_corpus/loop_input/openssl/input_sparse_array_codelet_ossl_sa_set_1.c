#include <stdio.h>
#include <inttypes.h>

typedef uintmax_t ossl_uintmax_t;

int level;
ossl_uintmax_t n;

void init_vars() {
    n = (ossl_uintmax_t)1 << (sizeof(ossl_uintmax_t) * 8 - 16);
}