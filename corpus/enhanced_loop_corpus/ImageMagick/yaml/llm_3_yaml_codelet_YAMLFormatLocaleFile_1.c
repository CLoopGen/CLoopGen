#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *value;
extern  char *p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array (simulated with pointer arithmetic)
    // Instead of direct traversal, we use a precomputed stride table (conceptually), but since we cannot allocate,
    // we simulate indirect access by using an offset list stored in a static array.
    // Here we assume maximum string length is bounded; we build an indirect access path with shuffled indices.

    // Static indirect index mapping: simulate non-sequential access (e.g., reverse order access)
    // We'll traverse the string in reverse by computing offsets from the end
    size_t len = 0;
    char *temp = value;
    while (temp[len] != '\x00') len++; // Compute length first

    for (size_t i = 0; i < len; i++) {
        p = value + (len - 1 - i); // Reverse access: indirect via computed offset

        switch (*p) {
          case '"':
          case '\b':
          case '\f':
          case '\n':
          case '\r':
          case '\t':
          case '\\':
            {
                if (~length < 1)
                    return;
                length++;
                break;
            }
          default:
            {
                if (((int)*p >= 0) && ((int)*p <= 31))
                    length += 6;
                break;
            }
        }
    }
}
