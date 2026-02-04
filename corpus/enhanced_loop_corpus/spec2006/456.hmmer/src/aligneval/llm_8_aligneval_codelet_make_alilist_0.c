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
    for (col = 0; s1[col] != '\x00' && s2[col] != '\x00'; col += 2) {
        if (col + 1 == 0 || s1[col + 1] == '\x00') break;
        int c1 = s1[col], c1n = s1[col + 1];
        int c2 = s2[col], c2n = s2[col + 1];
        int cond1_curr = !((c1) == ' ' || (c1) == '.' || (c1) == '_' || (c1) == '-' || (c1) == '~');
        int cond1_next = !((c1n) == ' ' || (c1n) == '.' || (c1n) == '_' || (c1n) == '-' || (c1n) == '~');
        int cond2_curr = !((c2) == ' ' || (c2) == '.' || (c2) == '_' || (c2) == '-' || (c2) == '~');
        int cond2_next = !((c2n) == ' ' || (c2n) == '.' || (c2n) == '_' || (c2n) == '-' || (c2n) == '~');

        if (cond1_curr) {
            s1_list[r1] = cond2_curr ? -1 : r2;
            r1++;
        }
        if (cond1_next) {
            s1_list[r1] = cond2_next ? -1 : r2;
            r1++;
        }

        if (cond2_curr) r2++;
        if (cond2_next) r2++;
    }
}
