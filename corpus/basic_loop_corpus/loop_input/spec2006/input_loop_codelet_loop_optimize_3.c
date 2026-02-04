#include <stdint.h>
#include <stdlib.h>

int *uid_luid;
int max_uid_for_loop;
int i;

void init_vars() {
    max_uid_for_loop = 65536; // Approximately 256KB of data (65536 ints * 4 bytes)
    uid_luid = (int*)calloc(max_uid_for_loop, sizeof(int));
    if (!uid_luid) return;
    // Ensure the loop runs for many iterations but eventually breaks
    // Set first non-zero value near the end to simulate worst-case scanning
    uid_luid[max_uid_for_loop - 1] = 42;
}