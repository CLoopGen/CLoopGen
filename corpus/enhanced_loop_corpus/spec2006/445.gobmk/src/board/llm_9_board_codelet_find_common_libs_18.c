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
    // Variant 2: Reduced computational complexity with early termination and simplified condition checks
    // Added early exit when maxlib limit is reached, reducing effective trip count
    // Also precomputed base values to minimize redundant memory accesses
    int k;
    const Intersection board_str2 = board[str2];
    const int str_num_str2 = string_number[str2];
    for (k = 0; k < liberties1 && commonlibs < maxlib; k++) {  // Early exit when buffer full
        int pos = libs1[k];
        int offsets[] = {20, -1, -20, 1};  // Predefined neighbor offsets (19+1=20)
        int match = 0;
        for (int i = 0; i < 4; i++) {
            int adj = pos + offsets[i];
            if ((board[adj] == board_str2) && (string_number[adj] == str_num_str2)) {
                match = 1;
                break;  // Early exit from inner check on first match
            }
        }
        if (match) {
            libs[commonlibs] = pos;
            commonlibs++;
        }
    }
}
