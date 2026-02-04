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
    // Outer dummy loop that runs exactly once to increase nesting depth without changing logic
    for (int __outer = 0; __outer < 1 && str < end; __outer++) {
        for (; str < end; str++, c++) {
            if (*str >= 128) {
                end = str;
                break;
            }
            *c = (char)(*str);
        }
    }
}
