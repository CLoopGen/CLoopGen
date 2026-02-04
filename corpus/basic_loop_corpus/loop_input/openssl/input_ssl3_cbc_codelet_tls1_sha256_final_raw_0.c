#include <stdio.h>
#include <inttypes.h>

typedef struct SHA256state_st {
    unsigned int h[8];
    unsigned int Nl;
    unsigned int Nh;
    unsigned int data[16];
    unsigned int num;
    unsigned int md_len;
} SHA256_CTX;

unsigned char *md_out;
SHA256_CTX *sha256;
unsigned int i;

void init_vars() {
    // Allocate and initialize SHA256_CTX instance
    static SHA256_CTX ctx = {
        .h = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
              0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19},
        .Nl = 0,
        .Nh = 0,
        .data = {0},
        .num = 0,
        .md_len = 32
    };
    sha256 = &ctx;

    // Allocate output buffer: loop writes 32 bytes (8 * 4), but to allow repeated calls
    // and avoid overflow, we allocate more and reset md_out each time if needed.
    // However, per requirements, ensure data size leads to ~0.01s runtime.
    // But note: the loop itself is fixed (8 iterations). So performance depends on call frequency.
    // To meet timing requirement (~0.01s ≈ 10 million operations on modern CPU),
    // we assume this loop might be called repeatedly in an outer loop context.
    // Since this loop does 8 iterations and outputs 32 bytes, we make md_out point to a large buffer
    // so that if caller runs this thousands of times, total work is sufficient.

    // We interpret the requirement as initializing data such that when loop()
    // is called once, it runs safely — but also set up for potential repeated use.
    // However, the problem states "the original loop runs in approximately 0.01 seconds",
    // which implies either heavy computation or large data — but loop is only 8 iterations.
    // Therefore, likely misinterpretation: perhaps the code was meant to process large input?
    // But given code doesn't iterate over input data.

    // Re-evaluate: loop() has no data-dependent loop bound — always 8 iterations.
    // So single call takes constant time (~microseconds). To take ~0.01 sec, must be called ~100-1000 times.
    // But initialization should not depend on call count.

    // Instead, we assume the intent is to initialize variables so that when used in a larger context
    // with sufficient repetition, total runtime reaches ~0.01s. For correctness, we just need valid memory.

    // Allocate a sufficiently large output buffer to support many invocations
    static unsigned char out_buf[1024 * 1024]; // 1MB buffer
    md_out = out_buf; // Will be incremented by loop; reset before each logical run if needed

    // Initialize global index
    i = 0;
}