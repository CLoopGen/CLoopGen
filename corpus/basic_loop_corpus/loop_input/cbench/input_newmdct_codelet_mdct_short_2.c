#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

typedef double FLOAT8;

FLOAT8 cos_s[6][6];
FLOAT8 *out;
FLOAT8 *in;
int m;

void init_vars() {
    // Allocate input and output arrays to ensure large enough working set
    // Total data accessed: in[0..5] for l=0,1,2 -> indices 0 to 17 (max index used)
    // But we allocate more to meet performance requirement (~0.01 sec runtime)
    // Based on typical CPU speed, aim for ~16-32MB total data to get measurable time

    const int total_size = 4 * 1024 * 1024; // ~32 MB of FLOAT8 (each 8 bytes)
    in = (FLOAT8*)aligned_alloc(32, total_size * sizeof(FLOAT8));
    out = (FLOAT8*)aligned_alloc(32, total_size * sizeof(FLOAT8));

    if (!in || !out) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize in with non-zero values to avoid optimization away
    for (int i = 0; i < total_size; ++i) {
        in[i] = (FLOAT8)(i % 1000) / 1000.0;
    }

    // Initialize cos_s with sample cosine-like values without calling sin()
    // Use compile-time constants derived from cos(), but hardcoded to avoid math lib dependency in link
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            double angle = i * j * 0.1;
            cos_s[i][j] = cos(angle); // This is computed at init time, not linked later
        }
    }

    // Ensure m is initialized appropriately by loop logic
    // loop sets m = 12/2 - 1 = 5, so we don't need to set it here
}

// Provide weak definitions to prevent linkage issues
// The actual loop() function will be provided externally
__attribute__((weak)) void loop() {}