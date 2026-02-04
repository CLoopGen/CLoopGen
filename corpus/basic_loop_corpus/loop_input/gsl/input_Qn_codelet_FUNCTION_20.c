#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

int ni;
int *p;
int *q;
int i;
long sump;
long sumq;

void init_vars() {
    ni = 64 * 1024 * 1024; // 64M elements, roughly 1-2 seconds but optimized may run faster; adjust if needed

    p = (int*)aligned_alloc(32, ni * sizeof(int));
    q = (int*)aligned_alloc(32, ni * sizeof(int));

    if (!p || !q) {
        // In a real scenario we might handle this, but since we must not include stdio or exit,
        // we assume allocation succeeds.
        return;
    }

    for (int idx = 0; idx < ni; ++idx) {
        p[idx] = idx % 256;
        q[idx] = (idx + 1) % 256;
    }

    sump = 0;
    sumq = 0;
    i = 0;
}