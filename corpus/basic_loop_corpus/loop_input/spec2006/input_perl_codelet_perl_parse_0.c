#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned long UV;

int PL_origargc = 100000;
char **PL_origargv;
char *s;
int i;
UV mask;
UV aligned;

void init_vars() {
    // Allocate and initialize s with a string of length ~1KB to control runtime
    s = malloc(1024);
    if (!s) exit(1);
    memset(s, 'a', 1023);
    s[1023] = '\0';

    // Set mask to align to 8-byte boundary: e.g., 0xFFFFFFFFFFFFFFF8
    mask = ~(UV)(7);

    // Set aligned flag: enable the range check path
    aligned = 1;

    // Allocate PL_origargv to hold many pointers
    PL_origargv = malloc(PL_origargc * sizeof(char*));
    if (!PL_origargv) exit(1);

    // Fill PL_origargv with valid pointers within controlled ranges
    for (int idx = 0; idx < PL_origargc; idx++) {
        // Most entries will satisfy the condition: > s and <= (char*)((UV)(s+8) & mask)
        // Compute aligned end boundary
        char* base = s;
        char* aligned_end = (char*)((UV)(base + 8) & mask);

        if (idx == 0) {
            // First argument doesn't match condition
            PL_origargv[idx] = base - 1; // Less than s
        } else if (idx == 1) {
            // Second argument matches exact pointer s+1
            PL_origargv[idx] = base + 1;
        } else {
            // Subsequent ones fall into the aligned range or just above
            if (aligned_end > base) {
                PL_origargv[idx] = (base + 2); // Within range
            } else {
                PL_origargv[idx] = base + 1;
            }
        }
    }

    // Ensure that eventually the loop breaks by having some entry fail the condition
    // Insert break after a large number of iterations — let loop run long enough
    // We set PL_origargc so that inner while loop dominates time

    // Adjust PL_origargc to control total runtime (~0.01 sec)
    // Each iteration advances s via while(*s) s++, but s is reset
    // Actually, s is being updated to point to end of string each time
    // So we need to ensure s points to a non-empty string initially

    // Already initialized s with 1KB string -> while(*s) takes about 1K iterations
    // Total time: ~ PL_origargc * strlen(s) operations
    // Want ~10M operations for ~0.01 sec on modern CPU
    // So if strlen(s)=1024, then PL_origargc ~ 10000 gives ~10M ops
    // But we already set PL_origargc = 100000 above -> adjust down slightly
    // However, only first few entries pass the test due to string bounds?
    // Let's ensure more entries pass but still terminate

    // Reset s to start again
    char* temp = malloc(1024);
    strcpy(temp, s);
    s = temp;

    // Make sure early argv entries are valid and trigger the body
    for (int idx = 1; idx < 1000 && idx < PL_origargc; idx++) {
        PL_origargv[idx] = s + 1; // All point near s to keep matching
    }
    // After 1000 iterations, break condition
    if (PL_origargc > 1000) {
        for (int idx = 1000; idx < PL_origargc; idx++) {
            PL_origargv[idx] = s - 10; // Doesn't satisfy condition -> break
        }
    }
}