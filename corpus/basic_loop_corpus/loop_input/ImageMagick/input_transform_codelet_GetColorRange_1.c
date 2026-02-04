#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    // Initialize the start_color array with a pattern that ensures safe traversal
    // and triggers the nested loop logic without causing out-of-bounds access.
    //
    // We fill 4096 bytes (page size) to match the declared array size.
    // The data is crafted so that:
    //   - It does not contain '-' or '\0' too early to avoid premature termination.
    //   - Contains '(' followed by non ')' characters, then a ')', simulating valid input.
    //   - Ends with a null terminator at the very end to ensure safety.

    for (int i = 0; i < 4095; i++) {
        start_color[i] = 'a' + (i % 26);
    }

    // Insert an opening parenthesis at position 1000
    start_color[1000] = '(';
    // Insert closing parenthesis at position 2000
    start_color[2000] = ')';
    // Ensure no '-' appears
    // Null terminate at the end
    start_color[4095] = '\0';

    // Initialize p to point to start of start_color
    p = start_color;
}