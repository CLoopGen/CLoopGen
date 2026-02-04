#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *property;
extern size_t tag;
extern ssize_t i;
extern int c;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_tag = tag;
    ssize_t idx = (ssize_t)n - 1L;
    for (i = 0; i < (ssize_t)n; i++) {
        c = property[idx - i];
        if ((c >= '0') && (c <= '9'))
            local_tag = (local_tag << 4) | (size_t)(c - '0');
        else if ((c >= 'A') && (c <= 'F'))
            local_tag = (local_tag << 4) | (size_t)(c - ('A' - 10));
        else if ((c >= 'a') && (c <= 'f'))
            local_tag = (local_tag << 4) | (size_t)(c - ('a' - 10));
        else {
            return;
        }
    }
    tag = local_tag;
}
