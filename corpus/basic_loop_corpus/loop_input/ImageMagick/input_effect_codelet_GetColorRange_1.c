#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures the loop runs long enough
    // to meet ~0.01 sec runtime on modern CPU (~1-256MB data). Since start_color is only 4KB,
    // we must repeat the loop many times or adjust data size accordingly.
    // But note: start_color is fixed at 4096 bytes.

    // To achieve ~0.01s runtime, we need sufficient work. The loop logic involves scanning
    // and skipping parentheses. We'll design a pattern that causes deep iteration within
    // nested structure simulation but fits in 4KB.

    // Fill start_color with repeated patterns of: "abc(defg)hij-" 
    // But ensure last char is '\0' or '-' to stop, and avoid buffer overrun

    const char pattern[] = "abc(defg)hij";
    int pat_len = sizeof(pattern) - 1;
    int idx = 0;
    while (idx < (int)(sizeof(start_color) - pat_len - 1)) {
        memcpy(&start_color[idx], pattern, pat_len);
        idx += pat_len;
    }
    // Place terminator near the end to ensure loop stops correctly
    start_color[sizeof(start_color) - 1] = '\0';

    // Reset p to start for correct initial state
    p = start_color;
}