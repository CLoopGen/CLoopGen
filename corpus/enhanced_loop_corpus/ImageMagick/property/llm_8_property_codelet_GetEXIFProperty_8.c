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
    for (i = (ssize_t)n - 1L; i >= 0; i -= 2) {
        if (i < 1) break;
        c = property[i];
        int c_next = property[i-1];
        tag <<= 8;
        if ((c >= '0') && (c <= '9'))
            tag |= (size_t)(c - '0');
        else if ((c >= 'A') && (c <= 'F'))
            tag |= (size_t)(c - ('A' - 10));
        else if ((c >= 'a') && (c <= 'f'))
            tag |= (size_t)(c - ('a' - 10));
        else
            return;

        if ((c_next >= '0') && (c_next <= '9'))
            tag |= (size_t)(c_next - '0') << 4;
        else if ((c_next >= 'A') && (c_next <= 'F'))
            tag |= (size_t)(c_next - ('A' - 10)) << 4;
        else if ((c_next >= 'a') && (c_next <= 'f'))
            tag |= (size_t)(c_next - ('a' - 10)) << 4;
        else
            return;
    }
}
