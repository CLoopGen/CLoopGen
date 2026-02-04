#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *value;
extern  char *p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char* outer_p;
    for (outer_p = value; *outer_p != '\x00'; outer_p++) {
        p = outer_p;
        for (int iter = 0; iter < 1; iter++) {  // Artificially nested single-iteration inner loop
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
}
