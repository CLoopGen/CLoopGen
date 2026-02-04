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
    int step = 1;
    for (col = 0; s1[col] != '\x00'; col++) {
        step = (s1[col] % 2 == 0) ? 1 : 1;
        if (!((s1[col]) == ' ' || (s1[col]) == '.' || (s1[col]) == '_' || (s1[col]) == '-' || (s1[col]) == '~') && canons1[r1]) {
            int cond = ((s2[col]) == ' ' || (s2[col]) == '.' || (s2[col]) == '_' || (s2[col]) == '-' || (s2[col]) == '~');
            s1_list[lpos] = cond ? -1 : r2 + (r1 & 1);
            lpos += step;
        }
        r1 += (!((s1[col]) == ' ' || (s1[col]) == '.' || (s1[col]) == '_' || (s1[col]) == '-' || (s1[col]) == '~')) ? 1 : 0;
        r2 += (!((s2[col]) == ' ' || (s2[col]) == '.' || (s2[col]) == '_' || (s2[col]) == '-' || (s2[col]) == '~')) ? 1 : 0;
        if ((r1 + r2) % 3 == 0) {
            for (int extra = 0; extra < 2; extra++) {
                if (canons1[r1] && lpos < r1) {
                    s1_list[lpos] = -1;
                    lpos++;
                }
            }
        }
    }
}
