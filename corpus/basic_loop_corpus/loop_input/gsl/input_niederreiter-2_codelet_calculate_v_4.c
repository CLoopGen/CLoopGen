#include <stdlib.h>
#include <stddef.h>

int r;
int kj = 1 << 20; // 1 million elements, sufficient for ~0.01 sec runtime
int v[1 << 20];   // Fixed-size array large enough to cover index up to kj-1

void init_vars() {
    // No additional initialization needed since v and kj are already initialized
    // Ensure r is within bounds when loop starts; loop sets r=0
}