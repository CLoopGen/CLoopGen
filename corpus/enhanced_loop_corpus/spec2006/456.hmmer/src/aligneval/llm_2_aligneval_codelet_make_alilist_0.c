#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int *s1_list;
extern int col;
extern int r1;
extern int r2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (col = 0; s1[col] != '\x00'; col += 2) {
        if (col + 1 == '\x00') break; // Prevent out-of-bounds if string length is odd
        if (!((s1[col]) == ' ' || (s1[col]) == '.' || (s1[col]) == '_' || (s1[col]) == '-' || (s1[col]) == '~')) {
            s1_list[r1] = ((s2[col]) == ' ' || (s2[col]) == '.' || (s2[col]) == '_' || (s2[col]) == '-' || (s2[col]) == '~') ? -1 : r2;
            r1++;
        }
        if (!((s2[col]) == ' ' || (s2[col]) == '.' || (s2[col]) == '_' || (s2[col]) == '-' || (s2[col]) == '~'))
            r2++;
        // Process next element in stride if within bounds
        if (s1[col+1] != '\x00') {
            if (!((s1[col+1]) == ' ' || (s1[col+1]) == '.' || (s1[col+1]) == '_' || (s1[col+1]) == '-' || (s1[col+1]) == '~')) {
                s1_list[r1] = ((s2[col+1]) == ' ' || (s2[col+1]) == '.' || (s2[col+1]) == '_' || (s2[col+1]) == '-' || (s2[col+1]) == '~') ? -1 : r2;
                r1++;
            }
            if (!((s2[col+1]) == ' ' || (s2[col+1]) == '.' || (s2[col+1]) == '_' || (s2[col+1]) == '-' || (s2[col+1]) == '~'))
                r2++;
        }
    }
}
