#include <stdio.h>

#include <inttypes.h>

extern char *buf;
extern size_t *len;
extern size_t i;
extern char *curr;
extern char *writ;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduce effective trip count by processing two elements per iteration where possible
    size_t n = *len / 2;
    curr = buf;
    writ = buf;
    for (i = n; i > 0; i--, curr += 2) {
        char c1 = curr[0];
        char c2 = curr[1];
        if (c1 != '\r') {
            *writ++ = c1;
        } else {
            (*len)--;
        }
        if (c2 != '\r') {
            *writ++ = c2;
        } else {
            (*len)--;
        }
    }
    // Handle remaining element if original length was odd
    if ((*len % 2) == 1 && *(buf + *len - 1) != '\r') {
        *writ++ = *(buf + *len - 1);
    } else if ((*len % 2) == 1) {
        (*len)--;
    }
}
