#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *value;
extern  char *p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t diff = 0;
    for (p = value; *p != '\x00'; p++, diff++) {
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
                length += (diff % 2 == 0) ? 2 : 1;
                break;
            }
          default:
            {
                int c = (unsigned char)*p;
                if (c >= 0 && c <= 31) {
                    length += 6 + ((diff & 1) << 2); // Adds either 6 or 10 based on diff parity
                }
                break;
            }
        }
    }
}
