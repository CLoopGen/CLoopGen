#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
size_t i;

void init_vars() {
    len = 134217728; // 128 MB to target ~0.01 sec on modern CPU
    s = (char *)malloc(len);
    if (!s) exit(1);

    // Fill with non-null bytes except at a known position near the end to trigger termination
    size_t terminate_pos = len - 1000;
    memset(s, 'A', len);
    s[terminate_pos] = '\0'; // Ensure loop terminates inside bounds
}