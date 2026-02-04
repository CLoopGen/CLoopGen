#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t Py_UCS4;

extern  Py_UCS4 *str;
extern  Py_UCS4 *end;
extern char *c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling (stride-2)
    Py_UCS4 *p = str;
    char *dst = c;
    for (; p + 1 < end; p += 2, dst += 2) {
        if ((p[0] >= 128)) {
            end = p;
            break;
        }
        dst[0] = (char)(p[0]);
        if ((p[1] >= 128)) {
            end = p + 1;
            break;
        }
        dst[1] = (char)(p[1]);
    }
    // Handle leftover element
    if (p < end) {
        if ((*p >= 128)) {
            end = p;
        } else {
            *dst = (char)(*p);
        }
        str = p + 1;
        c = dst + 1;
    } else {
        str = p;
        c = dst;
    }
}
