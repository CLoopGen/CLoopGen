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
    int i, base_lpos = lpos;
    for (i = 0; s1[i] != '\x00'; i++) {
        if (!((s1[i]) == ' ' || (s1[i]) == '.' || (s1[i]) == '_' || (s1[i]) == '-' || (s1[i]) == '~')) {
            if (canons1[r1]) {
                s1_list[base_lpos] = ((s2[i]) == ' ' || (s2[i]) == '.' || (s2[i]) == '_' || (s2[i]) == '-' || (s2[i]) == '~') ? -1 : r2;
                base_lpos++;
            }
            r1++;
            if (!((s2[i]) == ' ' || (s2[i]) == '.' || (s2[i]) == '_' || (s2[i]) == '-' || (s2[i]) == '~'))
                r2++;
        } else {
            if (!((s2[i]) == ' ' || (s2[i]) == '.' || (s2[i]) == '_' || (s2[i]) == '-' || (s2[i]) == '~'))
                r2++;
        }
    }
    lpos = base_lpos;
}
