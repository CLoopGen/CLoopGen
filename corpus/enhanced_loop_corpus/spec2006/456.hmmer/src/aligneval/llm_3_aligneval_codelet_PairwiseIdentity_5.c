#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int idents;
extern int len1;
extern int len2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward and reverse access using dual indexing
    int forward = 0;
    int backward = 0;

    // Compute string lengths first to enable reverse indexing
    while (s1[backward] != '\x00') backward++;
    backward--; // Point to last valid character

    while (s2[forward] != '\x00') forward++;
    forward--;

    // Traverse from start of s1 and end of s2 moving inward
    for (x = 0; x <= backward && x <= forward; x++) {
        char c1 = s1[x];           // Forward access on s1
        char c2 = s2[forward - x]; // Reverse (strided downward) access on s2

        if (!(c1 == ' ' || c1 == '.' || c1 == '_' || c1 == '-' || c1 == '~')) {
            len1++;
            if (c1 == c2)
                idents++;
        }
        if (!(c2 == ' ' || c2 == '.' || c2 == '_' || c2 == '-' || c2 == '~'))
            len2++;
    }
}
