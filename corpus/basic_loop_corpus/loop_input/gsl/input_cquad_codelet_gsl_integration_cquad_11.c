#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    double a;
    double b;
    double c[64];
    double fx[33];
    double igral;
    double err;
    int depth;
    int rdepth;
    int ndiv;
} gsl_integration_cquad_ival;

int n[4];
int idx[4];
double temp;
int i;
int d;
gsl_integration_cquad_ival *iv;
double nc;
double ncdiff;

void init_vars() {
    // Set d to 1 to ensure d-1 is valid (0), and use n[0] as loop bound
    d = 1;

    // We need to ensure: i <= n[d-1] => i <= n[0]
    // Also access iv->c[idx[d-1]+i] and iv->c[idx[d]+i] => idx[0]+i and idx[1]+i must be < 64
    // So we require: idx[0] + n[0] < 64 and idx[1] + n[0] < 64

    // Choose n[0] such that the loop runs long enough (~0.01 sec)
    // On modern CPU, ~1e8 operations ~ 0.01 sec. Each loop iteration is a few flops.
    // Let's aim for ~1e7 iterations.

    n[0] = 10000000;  // 10 million iterations
    n[1] = 0;
    n[2] = 0;
    n[3] = 0;

    idx[0] = 0;  // so idx[d-1] = idx[0] = 0
    idx[1] = 32; // so idx[d] = idx[1] = 32, then idx[d]+i = 32+i, needs i < 32 to stay in bounds? But i up to 10M!
    
    // Wait: iv->c has only 64 elements. So idx[x] + i must be < 64.
    // But i goes up to 10M -> impossible unless we reinterpret?

    // Rethink: likely the original code assumes small n[d-1]. 
    // But requirement says "data size 1MB–256MB"
    // So perhaps iv is an array of structs?

    // Let's reinterpret: make iv point to a large array of structures, but still each .c has 64 doubles.
    // But indexing: iv->c[idx[d-1] + i] — if iv is a single struct, index must be <64.
    // So to have large i, we must have small n[d-1]? Contradiction.

    // Alternative: maybe "idx" arrays are used to pick base indices, and i is small.
    // But requirement: run ~0.01 sec. So we need enough work.

    // Compromise: make n[0] = 1000000 (1M) and set idx values so that indexing stays within [0,63]
    // But 1M > 64 -> out of bounds.

    // Therefore, we must assume that the loop index i does not go beyond buffer bounds.
    // So n[d-1] must be <= 63 - max(idx[0], idx[1])

    // So maximum n[0] is about 60. That gives only 60 iterations -> too fast.

    // Unless... the structure's c array is not the only data? Or iv is an array?

    // Looking at the code: iv->c[idx[d-1] + i] — this suggests that the offset is (idx[d-1] + i)
    // So if we set idx[d-1] = 0 and n[d-1] = 63, then i from 0 to 63 -> 64 iterations.

    // But 64 iterations is too few for 0.01s.

    // Another possibility: typo? Maybe it's iv[i].c[idx[...]] ?

    // But the code says: iv->c[...]

    // So only one struct.

    // Therefore, we cannot have large i.

    // But requirement: 1MB–256MB data.

    // How much data do we have?
    // Currently, only one gsl_integration_cquad_ival struct: size is about:
    //   double: 1 + 1 + 64 + 33 + 1 + 1 = 101 * 8 = 808 bytes
    //   int: 3 * 4 = 12, plus padding -> ~820 bytes.

    // Not meeting data size.

    // Therefore, we must reinterpret iv as a pointer to a large block.

    // But the code uses iv->c[...] — so iv must be a pointer to struct.

    // Unless we allocate a large array of these structs and access via iv[some_index]?
    // But the code uses iv->, not iv[i].

    // So it's a single instance.

    // This leads to a contradiction between memory access bounds and data size.

    // Resolution: perhaps the problem allows us to scale the struct?
    // But the struct is given.

    // Alternative: ignore the 1MB–256MB if it's impossible, or reinterpret the access.

    // But requirement: avoid out-of-bounds.

    // Final decision: prioritize correctness (no out-of-bounds) over data size.
    // Use smaller n[0] that fits in c[64].

    // Let n[0] = 60, idx[0] = 0, idx[1] = 4 -> then idx[0]+i <= 60, idx[1]+i <= 64 -> ok.

    n[0] = 60;
    n[1] = 0;
    n[2] = 0;
    n[3] = 0;

    idx[0] = 0;
    idx[1] = 4;
    idx[2] = 0;
    idx[3] = 0;

    // Allocate and initialize iv
    iv = (gsl_integration_cquad_ival*)malloc(sizeof(gsl_integration_cquad_ival));
    if (!iv) exit(1);

    // Initialize c arrays to avoid NaN issues
    for (int j = 0; j < 64; j++) {
        iv->c[j] = (double)(j + 1);
    }

    // Initialize other variables
    temp = 0.0;
    i = 0;
    d = 1;
    nc = 0.0;
    ncdiff = 0.0;
}