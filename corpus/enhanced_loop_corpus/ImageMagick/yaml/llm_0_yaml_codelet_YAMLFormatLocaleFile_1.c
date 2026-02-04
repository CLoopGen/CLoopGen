#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *value;
extern  char *p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = value; *p != '\x00'; p++) {
        if (*p == '"' || *p == '\b' || *p == '\f' || *p == '\n' || *p == '\r' || *p == '\t' || *p == '\\') {
            if (~length < 1)
                return;
            length++;
        } else if (((int)*p >= 0) && ((int)*p <= 31)) {
            length += 6;
        }
    }
}
