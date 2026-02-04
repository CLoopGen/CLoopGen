#include <stdio.h>

#include <inttypes.h>

struct cpp_string {
    unsigned int len;
    const unsigned char *text;
};


typedef struct cpp_string cpp_string;

extern  cpp_string *in;
extern  unsigned char *src;
extern  unsigned char *limit;
extern char *dest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 iterations
    unsigned char *s = in->text;
    unsigned char *end = s + in->len;
    unsigned char *d = dest;

    for (; s < end - 1; s += 2, d += 2) {
        if (*s == '\\' && (s[1] == '\\' || s[1] == '"')) {
            d[0] = *s++;
        } else {
            d[0] = *s;
        }
        d[1] = *s++;
    }

    // Handle last element if any
    if (s < end) {
        if (*s == '\\' && (s+1 < limit) && (s[1] == '\\' || s[1] == '"'))
            s++;
        *d++ = *s++;
    }

    dest = d; // Update global dest pointer
}
