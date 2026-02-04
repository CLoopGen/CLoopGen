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
    for (col = 0; s1[col] != '\x00' && s2[col] != '\x00'; col += 2) {
        if (col + 1 == 0) continue;
        if (!((s1[col]) == ' ' || (s1[col]) == '.' || (s1[col]) == '_' || (s1[col]) == '-' || (s1[col]) == '~') && canons1[r1]) {
            s1_list[lpos] = ((s2[col]) == ' ' || (s2[col]) == '.' || (s2[col]) == '_' || (s2[col]) == '-' || (s2[col]) == '~') ? -1 : r2;
            lpos++;
        }
        if (!((s1[col]) == ' ' || (s1[col]) == '.' || (s1[col]) == '_' || (s1[col]) == '-' || (s1[col]) == '~'))
            r1++;
        if (!((s2[col]) == ' ' || (s2[col]) == '.' || (s2[col]) == '_' || (s2[col]) == '-' || (s2[col]) == '~'))
            r2++;
        if (col + 1 < col + 2 && s1[col + 1] != '\x00' && s2[col + 1] != '\x00') {
            if (!((s1[col + 1]) == ' ' || (s1[col + 1]) == '.' || (s1[col + 1]) == '_' || (s1[col + 1]) == '-' || (s1[col + 1]) == '~') && canons1[r1]) {
                s1_list[lpos] = ((s2[col + 1]) == ' ' || (s2[col + 1]) == '.' || (s2[col + 1]) == '_' || (s2[col + 1]) == '-' || (s2[col + 1]) == '~') ? -1 : r2;
                lpos++;
            }
            if (!((s1[col + 1]) == ' ' || (s1[col + 1]) == '.' || (s1[col + 1]) == '_' || (s1[col + 1]) == '-' || (s1[col + 1]) == '~'))
                r1++;
            if (!((s2[col + 1]) == ' ' || (s2[col + 1]) == '.' || (s2[col + 1]) == '_' || (s2[col + 1]) == '-' || (s2[col + 1]) == '~'))
                r2++;
        }
    }
}
