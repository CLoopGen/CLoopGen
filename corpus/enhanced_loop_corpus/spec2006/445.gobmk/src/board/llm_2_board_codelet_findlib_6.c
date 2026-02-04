#include <stdio.h>

#include <inttypes.h>

struct string_data {
    int color;
    int size;
    int origin;
    int liberties;
    int libs[20];
    int neighbors;
    int neighborlist[160];
    int mark;
};


extern struct string_data string[240];
extern int maxlib;
extern int *libs;
extern int k;
extern int liberties;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    int *lib_ptr = libs;
    int *string_libs_ptr = string[s].libs;
    for (k = 0; k < maxlib && k < liberties; k++) {
        *lib_ptr++ = *string_libs_ptr++;
    }
}
