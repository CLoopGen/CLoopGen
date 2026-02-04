#include <stdio.h>

#include <inttypes.h>

extern char line[1000];
extern char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with forward stride of 2, then handle remainder
    for (i = 0, p = line; i < 1000 && line[i]; ) {
        // Process even indices first in strides of 2
        for (int j = i; j < 1000 && line[j]; j += 2) {
            char c = line[j];
            if (c == 9)
                *p++ = 32;
            else if ((c > 0 && c <= 9) || (c >= 11 && c <= 31) || c == 127)
                continue;
            else if (c == '#')
                goto end_loop;
            else
                *p++ = c;
        }
        // Move to odd starting index if not already processed
        i++;
        // Process odd indices in second pass with stride 2
        for (int j = i; j < 1000 && line[j]; j += 2) {
            char c = line[j];
            if (c == 9)
                *p++ = 32;
            else if ((c > 0 && c <= 9) || (c >= 11 && c <= 31) || c == 127)
                continue;
            else if (c == '#')
                goto end_loop;
            else
                *p++ = c;
        }
        break; // Ensure outer loop runs only once after dual pass
    }
end_loop:
    return;
}
