#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize start_color with a pattern that ensures the loop runs for a significant time
    // but without exceeding the 4096-byte boundary. We'll create a large string with nested
    // parentheses and ensure it ends with '-' to terminate early, but place '-' far enough
    // so that the loop processes a lot of data.

    // Target ~100ms execution: assume simple ops per byte, aim for ~10^7 operations.
    // But array is only 4KB = 4096 bytes. So we must repeat access? However, loop walks once.
    // So we cannot exceed 4096 iterations. That's too fast (~microseconds).
    // Therefore, we need to increase data size. But start_color is fixed at 4096.

    // Wait: the problem says "suggest 1MB–256MB", but start_color is declared as [4096].
    // So we must respect that. However, note: the extern declaration is fixed-size.
    // We cannot change size. So we must work within 4KB.

    // But 4KB is too small to take 0.01 seconds unless each byte takes many cycles.
    // The loop body is very simple: pointer increment and comparisons.
    // Even at 1e9 operations/sec, 4KB is done in microseconds.

    // Therefore, to meet timing, we must make the control flow cause repeated scanning?
    // But the loop increments p throughout and never resets.

    // Alternative interpretation: maybe the array should have been larger? But declaration fixes it.

    // Re-read: "generate ... defines and initializes all those external symbols"
    // and "ensure memory access does not go out of bounds".

    // We are stuck with 4096 bytes. So we can't meet 0.01 seconds by volume.
    // But perhaps on some slow machine? Or maybe the problem expects us to ignore timing
    // when the array size is fixed?

    // Since the array size is specified (4096), we follow that and initialize safely.

    // Fill start_color with a pattern that includes several "(...)" groups and ends with '-'
    int pos = 0;
    const char group[] = "abcdefghijklmnopqrstuvwxyz";
    const int group_len = sizeof(group) - 1;

    // Fill most of the buffer with non-delimiters
    while (pos < 4096 - 100) {
        if (pos + group_len + 3 < 4096 - 100) {
            start_color[pos++] = '(';
            for (int i = 0; i < group_len; i++) {
                start_color[pos++] = group[i];
            }
            start_color[pos++] = ')';
        } else {
            break;
        }
    }

    // Then fill remainder with normal characters
    while (pos < 4096 - 2) {
        start_color[pos++] = 'X';
    }

    // Ensure no ')' or '-' appears until the end
    start_color[pos++] = 'Y';
    start_color[pos++] = '-';
    start_color[pos] = '\0'; // This would be after '-', so not reached

    // Actually, we want the '-' to be the terminating condition
    // So set last few: ... Y, '-', '\0'
    if (pos < 4096 - 1) {
        start_color[pos-1] = '-';
    }
    if (pos < 4096) {
        start_color[pos] = '\0';
    } else {
        start_color[4095] = '\0';
    }

    // Reset p to start of array
    p = start_color;
}