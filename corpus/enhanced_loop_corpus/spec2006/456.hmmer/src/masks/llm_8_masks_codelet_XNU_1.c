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
for (off = mcut; off <= noff; off += 2) {
    sum = top = 0;
    beg = off;
    end = 0;
    for (i = off + 1; i <= len; i++) {
        sum += xpam120[(int)dsq[i]][(int)dsq[i - off]] + xpam120[(int)dsq[i-1]][(int)dsq[i - off - 1]];
        if (sum > top) {
            top = sum;
            end = i;
        }
        if (top >= topcut && top - sum > fallcut * 2) {
            for (k = beg; k <= end; k += 2)
                hit[k] = hit[k - off] = 1;
            sum = top = 0;
            beg = end = i + 1;
        } else if (top - sum > fallcut * 2) {
            sum = top = 0;
            beg = end = i + 1;
        }
        if (sum < 0) {
            beg = end = i + 1;
            sum = top = 0;
        }
    }
    if (top >= topcut) {
        for (k = beg; k <= end; k += 2)
            hit[k] = hit[k - off] = 1;
    }
}
}
