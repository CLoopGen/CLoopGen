#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *value;
extern  char *p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_p = value;
    size_t local_length = length;
    for (; *local_p != '\x00'; local_p++) {
        switch (*local_p) {
          case '"':
          case '\b':
          case '\f':
          case '\n':
          case '\r':
          case '\t':
          case '\\':
            {
                if (~(local_length) < 1)
                    goto end_loop1;
                local_length++;
                break;
            }
          default:
            {
                int c = (int)*local_p;
                if ((c >= 0) && (c <= 31))
                    local_length += 6;
                break;
            }
        }
    }
end_loop1:
    length = local_length;
}
