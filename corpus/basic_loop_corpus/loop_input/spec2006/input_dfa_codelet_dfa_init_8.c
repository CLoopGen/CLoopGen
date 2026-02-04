#include <inttypes.h>

int dfa_p[7056];
int ii;

void init_vars() {
    // The array dfa_p is already sized to 7056 elements, which matches the loop bound: 4 * 21 * 4 * 21 = 7056
    // No dynamic allocation needed; size is fixed and sufficient.
    // Variables are global, so they are zero-initialized by default, but we ensure readiness.
}

// The loop function uses ii and dfa_p, both now defined here as non-const since they are modified.