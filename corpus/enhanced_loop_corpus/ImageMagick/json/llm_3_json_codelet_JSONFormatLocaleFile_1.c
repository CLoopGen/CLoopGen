#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *value;
extern  char *p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via index array (simulated with pointer arithmetic as index buffer)
    // Simulate an indirect access pattern using a dynamically computed "index map" on stack
    // We'll create a virtual index list that reverses the order of access (reverse indirect traversal)
    size_t val_len = 0;
    const char *temp = value;
    while (temp && *temp != '\x00') {
        val_len++;
        temp++;
    }

    if (val_len == 0) return;

    // Simulate indirect access through reversed indices
    size_t i;
    size_t len = 0;
    for (i = 0; i < val_len; i++) {
        p = value + (val_len - 1 - i); // indirect access: reverse order
        switch (*p) {
            case '"':
            case '\b':
            case '\f':
            case '\n':
            case '\r':
            case '\t':
            case '\\':
                {
                    if (~(length + len) < 1)
                        return;
                    len++;
                    break;
                }
            default:
                {
                    int c = (int)(unsigned char)*p;
                    if (c >= 0 && c <= 31)
                        len += 6;
                    break;
                }
        }
    }
    length += len;
}
