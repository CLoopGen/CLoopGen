#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *a;
extern  unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    size_t count = 0;
    for (p = a; *p && count < 256; p++, count++) {
        if (!((*p >= '+' && *p <= ':') || (*p >= '@' && *p <= 'Z') || *p == '_' || (*p >= 'a' && *p <= 'z')) ||
            ((count % 3) == 0 && *p > 'M')) {
            break;
        }
    }
}
