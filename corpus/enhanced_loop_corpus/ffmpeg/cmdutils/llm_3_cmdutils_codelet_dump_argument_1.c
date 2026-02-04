#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *a;
extern  unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive two-element lookahead (unrolled-like pattern with dual checks)
    unsigned char *current = (unsigned char *)a;
    for (p = current; *p; ) {
        // Check current character
        if (!((*p >= '+' && *p <= ':') || (*p >= '@' && *p <= 'Z') || *p == '_' || (*p >= 'a' && *p <= 'z'))){
            break;
        }
        p++;
        // Optional second access in sequence (consecutive pattern)
        if (*p && !((*p >= '+' && *p <= ':') || (*p >= '@' && *p <= 'Z') || *p == '_' || (*p >= 'a' && *p <= 'z'))){
            break;
        }
        p++;
    }
}
