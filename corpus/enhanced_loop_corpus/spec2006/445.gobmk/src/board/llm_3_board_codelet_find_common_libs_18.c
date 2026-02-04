#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int string_number[400];
extern int str2;
extern int maxlib;
extern int *libs;
extern int *libs1;
extern int liberties1;
extern int commonlibs;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Access via Pointer Arithmetic and Reordered Checks
    // Use pointer arithmetic to access libs1 elements indirectly and reorder neighbor checks
    // to simulate different memory access locality patterns.

    int *lib_ptr = libs1;
    int temp_lib;
    commonlibs = 0;

    for (k = 0; k < liberties1; k++) {
        temp_lib = *(lib_ptr + k); // Indirect access using pointer arithmetic

        // Reorder condition checks to prioritize horizontal neighbors first, then vertical
        if (((board[temp_lib + 1] == board[str2]) && string_number[temp_lib + 1] == string_number[str2]) ||
            ((board[temp_lib - 1] == board[str2]) && string_number[temp_lib - 1] == string_number[str2]) ||
            ((board[temp_lib + 20] == board[str2]) && string_number[temp_lib + 20] == string_number[str2]) ||
            ((board[temp_lib - 20] == board[str2]) && string_number[temp_lib - 20] == string_number[str2])) {

            if (commonlibs < maxlib) {
                libs[commonlibs] = temp_lib;
            }
            commonlibs++;
        }
    }
}
