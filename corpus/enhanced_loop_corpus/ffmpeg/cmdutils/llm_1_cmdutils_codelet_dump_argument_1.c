#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *a;
extern  unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (p = a; *p; p++) {
    for (size_t i = 0; i < 1; i++) {
        if (!((*p >= '+' && *p <= ':') || (*p >= '@' && *p <= 'Z') || *p == '_' || (*p >= 'a' && *p <= 'z')))
            break;
    }
}
}
