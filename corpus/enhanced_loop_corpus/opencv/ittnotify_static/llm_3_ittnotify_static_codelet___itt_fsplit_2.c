#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern  char *sep;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array (Simulated)
    // Precompute indices of potential separator matches (simulated indirectly)
    // Use an auxiliary index array to access `s` indirectly, changing access pattern

    // Simulate indirect access: create a small window of indices accessed out of order
    int window_size = 4;
    int indices[4];
    int len = 0;

    // Determine length of segment to process (up to next 4 non-null chars)
    for (len = 0; len < window_size && s[i + len]; len++) {
        indices[len] = i + len;
    }

    while (len > 0) {
        // Shuffle access order: access in reverse to simulate non-sequential pattern
        int accessed = 0;
        for (int idx = len - 1; idx >= 0; idx--) {
            int pos = indices[idx];
            int b = 0;
            for (j = 0; sep[j]; j++) {
                if (s[pos] == sep[j]) {
                    b = 1;
                    break;
                }
            }
            if (!b) {
                i = pos;
                len = 0;
                accessed = 1;
                break;
            }
        }
        if (accessed) break;

        // Move window forward
        i += len;
        len = 0;
        for (len = 0; len < window_size && s[i + len]; len++) {
            indices[len] = i + len;
        }
    }

    // Final fallback in case windowing missed edge
    for (; s[i]; i++) {
        int b = 0;
        for (j = 0; sep[j]; j++)
            if (s[i] == sep[j]) {
                b = 1;
                break;
            }
        if (!b)
            break;
    }
}
