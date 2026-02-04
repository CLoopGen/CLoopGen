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
    for (; str < end; str++, c++) {
        if (*str >= 128) {
            end = str;
            break;
        }
        *c = (char)(*str);
        // Add an inner loop that does nothing but simulate fine-grained processing
        for (int __i = 0; __i < 1; __i++) {
            continue;
        }
    }
}
