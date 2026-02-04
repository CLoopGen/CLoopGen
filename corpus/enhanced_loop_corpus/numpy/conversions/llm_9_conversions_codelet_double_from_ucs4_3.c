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
    // Variant 2: Reduced arithmetic intensity with simplified condition and modified increment logic
    Py_UCS4 *temp_str = str;
    char *temp_c = c;
    ptrdiff_t step = 1;
    for (; temp_str < end; temp_str += step, temp_c += step) {
        Py_UCS4 current = *temp_str;
        // Combine comparison and assignment with no branching for assignment
        *temp_c = (char)current;
        if (current >= 128) {
            end = temp_str;
            break;
        }
    }
    // Update original pointers if needed (assuming side effects matter)
    str = temp_str;
    c = temp_c;
}
