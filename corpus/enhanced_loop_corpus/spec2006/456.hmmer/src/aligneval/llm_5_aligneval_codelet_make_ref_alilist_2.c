#include <stdio.h>

#include <inttypes.h>

extern char *s1;
extern char *s2;
extern int *s1_list;
extern int col;
extern int r1;
extern int r2;
extern int *canons1;
extern int lpos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (col = 0; s1[col] != '\x00'; col++) {
    int is_valid_s1 = (s1[col]) == ' ' || (s1[col]) == '.' || (s1[col]) == '_' || (s1[col]) == '-' || (s1[col]) == '~';
    int is_valid_s2 = (s2[col]) == ' ' || (s2[col]) == '.' || (s2[col]) == '_' || (s2[col]) == '-' || (s2[col]) == '~';

    if (!is_valid_s1 && !is_valid_s2) {
        if (canons1[r1]) {
            s1_list[lpos] = r2;
            lpos++;
        }
        r1++;
        r2++;
    } else if (!is_valid_s1) {
        if (canons1[r1]) {
            s1_list[lpos] = -1;
            lpos++;
        }
        r1++;
        r2++;
    } else if (!is_valid_s2) {
        r2++;
    } else {
        // Both are valid, increment counters only if needed
        r1 += !is_valid_s1;
        r2 += !is_valid_s2;
    }
}
}
