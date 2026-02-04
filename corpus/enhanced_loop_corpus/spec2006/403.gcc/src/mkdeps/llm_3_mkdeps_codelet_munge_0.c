#include <stdio.h>

#include <inttypes.h>

extern  char *filename;
extern int len;
extern  char *p;
extern  char *q;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Permutation
    // Use an array of indices that defines a non-sequential traversal order (e.g., reverse order),
    // simulating indirect memory access patterns common in optimized or transformed loops.

    char *base = filename;
    int n = 0;
    while (base[n]) n++; // Compute length

    // Create indirect access via reversed index list
    int indices[1024]; // Assume max path length; in practice, dynamic alloc could be used
    if (n > 1024) return; // Prevent buffer overflow

    for (int i = 0; i < n; i++) {
        indices[i] = n - 1 - i; // Reverse order
    }

    len = 0;
    // Traverse characters in reverse order using indirect indexing
    for (int idx = 0; idx < n; idx++) {
        int pos = indices[idx]; // Indirect access position
        char c = base[pos];

        // Adjust length contribution based on original forward logic
        // Note: Since we're going backwards, adjust `len` as if scanning forward
        // This requires calculating how many characters would have been added up to this point
        // To keep semantics equivalent, we precompute expected contributions in reverse logic.

        switch (c) {
            case ' ':
            case '\t': {
                // Count trailing backslashes from this position forward in original string
                char *q = &base[pos] - 1;
                while (q >= filename && *q == '\\') {
                    len++;
                    q--;
                }
                len++; // For space/tab escaping
                break;
            }
            case '$':
                len++;
                break;
        }
        len++; // Each character contributes at least 1
    }

    // Final adjustment: because the original loop increments `len` per iteration,
    // and we've processed all characters, the total is preserved despite access order.
}
