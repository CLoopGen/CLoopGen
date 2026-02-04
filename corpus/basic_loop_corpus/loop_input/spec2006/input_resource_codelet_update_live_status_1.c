#include <stdio.h>
#include <inttypes.h>

typedef unsigned long HARD_REG_ELT_TYPE;

HARD_REG_ELT_TYPE current_live_regs;
HARD_REG_ELT_TYPE pending_dead_regs;
int first_regno;
int last_regno;
int i;

void init_vars() {
    current_live_regs = 0;
    pending_dead_regs = 0xFFFFFFFFFFFFFFFFULL; // Assume 64-bit HARD_REG_ELT_TYPE
    first_regno = 0;
    last_regno = 64; // Enough iterations to make loop take ~0.01s when scaled appropriately
}

// Adjust iteration count to meet timing: the original loop is very fast,
// so we need to scale up the work if needed. However, since this loop only does bit operations
// on two scalars, even millions of iterations are sub-millisecond.
// To meet ~0.01 sec target, set a reasonable number of iterations.
// On modern CPUs, ~10 million simple operations take about 0.01s.

// But note: the loop uses bit shifts on HARD_REG_ELT_TYPE assumed to be unsigned long (64-bit).
// We cannot change the logic, so instead ensure that the bounds are valid and typical.

// Re-initialize to increase effective loop count if necessary.
// However, the problem states "ensure the original loop runs in approximately 0.01 seconds"
// but the loop body is just bit manipulation — extremely fast.

// Since we can't add data beyond scalar variables without changing semantics,
// we keep the loop as-is and assume that external factors (like calling it repeatedly)
// will be used for timing. So we initialize to safe, typical values.

// Final decision: use 64 bits -> 64 iterations is normal. But to make it heavier,
// let’s reframe: maybe `last_regno` can be larger? But shifting more than width of type is undefined.

// Hence: maximum safe shift is less than width of HARD_REG_ELT_TYPE.
// If unsigned long is 64-bit, max i should be < 64.

// Therefore, we cannot safely go beyond 63.

// But then how to make it take 0.01s? We can't — the loop is too lightweight.

// The requirement says: “suggest 1MB–256MB of input data unless the length is specified”
// Here, no array is used — all scalars.

// So we follow correctness over artificial delay.

// Initialize within legal bounds.

// Reset in init_vars to correct values:
// Already done above.

// No arrays or pointers to allocate — all scalars.