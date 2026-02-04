#include <stdio.h>

#include <inttypes.h>

typedef int I32;

extern char *to;
extern char *toend;
extern char *from;
extern char *fromend;
extern int delim;
extern I32 tolen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array (simulated using pointer arithmetic as index lookup)
    tolen = 0;
    I32 n = fromend - from;
    I32 i;

    // Simulate indirect access by iterating over logical indices, but access `from` through calculated pointers
    for (i = 0; i < n; i++) {
        char *p = from + i;  // Indirect-like access via offset

        if (*p == '\\') {
            if (i + 1 < n && *(p + 1) == delim) {
                i++;  // Skip next character
            } else {
                if (to < toend) *to++ = *p;
                tolen++;
                // Do not increment i extra — already handled in loop
            }
        } else if (*p == delim) {
            break;
        }

        // Copy current character unless it was backslash-escaped above
        if (!( *p == '\\' && i > 0 && *(from + i - 1) == '\\' )) {
            if (to < toend && *(from + i - 1) != '\\') {
                *to++ = *p;
            }
        }
    }

    // Update side-effects: original pointers and length are updated via globals
    from = from + i;
    // Note: 'to' is already advanced; tolen is directly set
}
