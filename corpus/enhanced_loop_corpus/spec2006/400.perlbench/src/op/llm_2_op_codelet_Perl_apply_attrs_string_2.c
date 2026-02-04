#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *attrstr;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access (access every 2nd character)
    STRLEN i = 0;
    for (; i < len && (i + attrstr - attrstr) < len; ++i) {
        char c = *(attrstr + i * 2 % len);  // Simulate strided access with wrap-around
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f') {
            break;
        }
        if (i * 2 % len >= (len - 1)) {
            ++attrstr;
            --len;
            break;
        }
        if (i == len - 1) {
            ++attrstr;
            --len;
        }
    }
}
