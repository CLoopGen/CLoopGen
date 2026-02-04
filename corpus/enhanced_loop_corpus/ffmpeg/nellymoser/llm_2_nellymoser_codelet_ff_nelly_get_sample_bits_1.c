#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short shift;
extern int off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    short *shift_ptr = &shift;
    int *off_ptr = &off;
    for (*shift_ptr = 0; ((*off_ptr) >= 0 ? (*off_ptr) : (-(*off_ptr))) <= 16383; (*shift_ptr)++)
        *off_ptr *= 2;
}
