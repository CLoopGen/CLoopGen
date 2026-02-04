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
    // Variant 1: Strided Memory Access (stride of 2, then process remaining elements)
    tolen = 0;
    char *f = from;
    char *t = to;

    // Process pairs with stride-like pattern: handle two characters at a time where possible
    for (; f + 1 < fromend; f += 2) {
        if (*f == '\\') {
            if (*(f + 1) == delim) {
                if (t < toend) *t++ = *(f + 1);
                tolen++;
                f++;  // Skip escaped delimiter
            } else {
                if (t + 1 < toend) {
                    *t++ = *f;
                    *t++ = *(f + 1);
                }
                tolen += 2;
            }
            f++;  // Compensate for loop increment
        } else if (*f == delim) {
            break;
        } else {
            if (*(f + 1) == delim) {
                if (t < toend) *t++ = *f;
                tolen++;
                break;
            } else {
                if (t + 1 < toend) {
                    *t++ = *f;
                    *t++ = *(f + 1);
                }
                tolen += 2;
            }
        }
    }

    // Handle last element if needed
    if (f < fromend && *f != delim) {
        if (t < toend) *t++ = *f;
        tolen++;
    }

    to = t;
    from = f >= fromend ? fromend : (f < fromend && *f == delim ? f : fromend);
}
