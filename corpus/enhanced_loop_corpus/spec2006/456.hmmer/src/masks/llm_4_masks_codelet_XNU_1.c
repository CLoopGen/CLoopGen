#include <stdio.h>

#include <inttypes.h>

extern int xpam120[23][23];
extern char *dsq;
extern int len;
extern int i;
extern int k;
extern int off;
extern int sum;
extern int beg;
extern int end;
extern int top;
extern int topcut;
extern int fallcut;
extern int noff;
extern int mcut;
extern int *hit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (off = mcut; off <= noff; off++) {
    sum = top = 0;
    beg = off;
    end = 0;
    for (i = off + 1; i <= len; i++) {
        int dsqi = (int)dsq[i];
        int dsqimoff = (int)dsq[i - off];
        sum += xpam120[dsqi][dsqimoff];

        if (sum <= top) {
            if (top - sum > fallcut) {
                if (top >= topcut) {
                    for (k = beg; k <= end; k++)
                        hit[k] = hit[k - off] = 1;
                }
                sum = top = 0;
                beg = end = i + 1;
                continue;
            }
            if (sum < 0) {
                sum = top = 0;
                beg = end = i + 1;
                continue;
            }
        } else {
            top = sum;
            end = i;
        }
    }
    if (top >= topcut) {
        for (k = beg; k <= end; k++)
            hit[k] = hit[k - off] = 1;
    }
}
}
