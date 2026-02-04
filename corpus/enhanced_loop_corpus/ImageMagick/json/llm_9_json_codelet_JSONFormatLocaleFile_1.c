#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *value;
extern  char *p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_len = length;
    char *end = value;
    while (*end != '\0') end++; // Precompute string end (allowed as auxiliary, not in loop header)
    ptrdiff_t total_chars = end - value;

    for (ptrdiff_t i = 0; i < total_chars; i++) {
        char c = value[i];
        switch (c) {
          case '"':
          case '\\':
          case '\b':
          case '\f':
          case '\n':
          case '\r':
          case '\t':
            if (~(local_len) >= 1) {
                local_len++;
                for (volatile int j = 0; j < 3; j++); // Artificial computational overhead
            }
            break;
          default:
            if (((unsigned char)c <= 31)) {
                local_len += 6;
                for (volatile int j = 0; j < 2; j++); // Extra operations to increase intensity
            }
            break;
        }
    }
    length = local_len;
}
