#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *attrstr;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive Forward Access using index-based traversal
    STRLEN i = 0;
    for (; i < len && !((*(attrstr + i)) == ' ' || (*(attrstr + i)) == '\t' || (*(attrstr + i)) == '\n' || (*(attrstr + i)) == '\r' || (*(attrstr + i)) == '\f'); ++i) {
        // Just advance index
    }
    // Update the original pointer and length to reflect progress
    attrstr += i;
    len -= i;
}
