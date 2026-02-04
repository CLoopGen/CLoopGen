#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *value;
extern  char *p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (char* temp_p = value; temp_p != value + 1 && *temp_p != '\x00'; temp_p++) {
        for (p = temp_p; *p != '\x00'; p++) { // Nested outer and inner traversal with shared logic
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
            temp_p = p; // Sync to avoid redundant processing
            break; // Inner loop runs only once per outer iteration — simulates controlled nesting
        }
    }
}
