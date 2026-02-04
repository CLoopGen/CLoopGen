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
    Py_UCS4 *temp_str = str;
    char *temp_c = c;
    for (; temp_str < end; ) {
        Py_UCS4 current_char = *temp_str;
        if ((current_char >= 128)) {
            end = temp_str;
            break;
        }
        *temp_c = (char)(current_char);
        temp_str++;
        temp_c++;
    }
    str = temp_str;
    c = temp_c;
}
