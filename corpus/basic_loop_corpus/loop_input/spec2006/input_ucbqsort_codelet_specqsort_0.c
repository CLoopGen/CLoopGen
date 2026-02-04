#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int qsz;
char *base;
char c;
char *i;
char *j;
char *hi;

static char *data_buffer;

void init_vars() {
    // Set data size to ~64MB to ensure loop runs for measurable time (~0.01 sec on modern CPU)
    qsz = 64 * 1024 * 1024;  // 64 MB

    // Allocate buffer with malloc to ensure proper alignment and sufficient space
    data_buffer = (char *)malloc(qsz);
    if (!data_buffer) {
        exit(1);
    }

    // Initialize base to point to the allocated buffer
    base = data_buffer;

    // Initialize j to point to the middle of the array to avoid out-of-bounds in swap
    j = base + qsz / 2;

    // Ensure i starts at base, hi at base + qsz as per loop initialization
    // The loop logic suggests a swap between *i and *j while advancing both
    // We must ensure that both i and j stay within valid bounds during the loop.
    // However, the original loop does:
    //   c = *j; *j++ = *i; *i++ = c;
    // So both i and j are dereferenced and then incremented.

    // Since i goes from base to base+qsz-1, and j starts at base+qsz/2,
    // we must ensure j doesn't go beyond allocated memory.
    // The loop runs (hi - i) = qsz iterations, so j will be incremented qsz times.
    // Therefore, j must start at a position such that j + qsz <= data_buffer + qsz
    // That implies j must start at data_buffer, but original sets j independently.

    // But in the provided loop: j is used before being initialized!
    // So we must initialize j to a valid position such that during the loop,
    // both i and j remain in [base, base + qsz)

    // However, the loop runs for qsz steps, and both i and j are incremented qsz times.
    // i starts at base -> ends at base + qsz (exclusive use)
    // j starts at some value -> ends at j + qsz

    // To prevent overflow, we require: j + qsz <= base + qsz  => j <= base
    // But j is set to base + qsz/2 initially, which violates this.

    // This indicates the original code likely has a bug or our interpretation is off.

    // Re-examining: the loop initializes i=base, hi=base+qsz, then runs while i<hi.
    // Each iteration: i++, j++
    // So it runs exactly qsz times.

    // Therefore, j must be initialized such that j + qsz <= allocated_size from base.

    // Our buffer is only qsz big. So j must start at base or before? But we can't go before.

    // Hence: j must start at base to have j + qsz = base + qsz, which is just at the limit.

    // But the original code uses *j at first access — so j must be in [base, base+qsz)

    // Conclusion: to run safely, j must start at base, not base + qsz/2.

    // However, the user's code may intend j to be pre-initialized elsewhere.
    // But since it's extern and used without prior init in loop, we must initialize it.

    // Given the risk of overflow, we adjust j to start at base, so both pointers walk together.

    j = base;

    // Clear any previous assumptions
    c = 0;

    // Explicitly do not set i or hi here — the loop itself initializes them:
    // for (i = base, hi = base + qsz; ...)

    // But we must ensure base + qsz is valid — it is, since buffer is qsz bytes, so base + qsz is one past last.
}

__attribute__((destructor))
static void cleanup() {
    free(data_buffer);
}