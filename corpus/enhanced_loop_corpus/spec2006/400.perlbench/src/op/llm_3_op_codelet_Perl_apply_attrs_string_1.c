#include <stdio.h>

#include <inttypes.h>

typedef size_t STRLEN;

extern char *attrstr;
extern STRLEN len;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via lookup table (using a precomputed boolean skip table)
    // We change the access pattern to use a static lookup table for ASCII characters to decide skipping.
    // This introduces indirect memory access through a table, modifying data access behavior.

    static const _Bool skip[256] = {
        [' '] = 1, ['\t'] = 1, ['\n'] = 1, ['\r'] = 1, ['\f'] = 1
    };

    const unsigned char *p = (const unsigned char *)attrstr;
    STRLEN n = len;

    for (; n > 0 && skip[*p]; --n, ++p)
        ;

    attrstr = (char *)p;
    len = n;
}
