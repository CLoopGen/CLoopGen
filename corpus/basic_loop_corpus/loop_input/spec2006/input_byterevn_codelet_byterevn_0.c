#include <inttypes.h>

typedef int int32type;

int32type w[65536];
int n = 65536;
int32type old;
int32type newv;
int j;

void init_vars() {
    for (int i = 0; i < n; i++) {
        w[i] = (int32type)(i * 12345U + 67890U);
    }
    old = 0;
    newv = 0;
    j = 0;
}