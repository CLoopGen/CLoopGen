#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[268435456]; // 256MB buffer
char *p;

void init_vars() {
    // Initialize the large buffer with a pattern that includes nested parentheses and delimiters
    size_t size = sizeof(start_color);
    size_t i = 0;

    // Fill the buffer with a repeating pattern: "abc(defg)hij-klm" but mostly safe
    const char *pattern = "abc(defghijk)lmno-pqrs(tuvwxyz)abcd-efgh(ijklmn)opqr-stuv(wxyzab)cdef-";
    size_t pattern_len = strlen(pattern);

    while (i < size - pattern_len) {
        memcpy(&start_color[i], pattern, pattern_len);
        i += pattern_len;
    }

    // Ensure we don't exceed bounds; terminate early if needed
    // Make sure the last few bytes contain a '-' to stop the outer loop
    if (i < size) {
        start_color[size - 1] = '-';
    } else {
        start_color[size - 1] = '\x00';
    }

    // Reset p to point to start of buffer for initial state
    p = start_color;
}