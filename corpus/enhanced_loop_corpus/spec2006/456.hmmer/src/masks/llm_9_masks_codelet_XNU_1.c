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
    for (i = off + 1; i <= len - 4; i += 4) {
        int s0 = xpam120[(int)dsq[i    ]][(int)dsq[i - off]];
        int s1 = xpam120[(int)dsq[i + 1]][(int)dsq[i - off + 1]];
        int s2 = xpam120[(int)dsq[i + 2]][(int)dsq[i - off + 2]];
        int s3 = xpam120[(int)dsq[i + 3]][(int)dsq[i - off + 3]];
        sum += s0 + s1 + s2 + s3;

        if (sum > top) {
            top = sum;
            end = i + 3;
        }

        if (top >= topcut && top - sum > fallcut) {
            for (k = beg; k <= end; k++)
                hit[k] = hit[k - off] = 1;
            sum = top = 0;
            beg = end = i + 5;
            break;
        } else if (top - sum > fallcut) {
            sum = top = 0;
            beg = end = i + 5;
            break;
        }
        if (sum < 0) {
            beg = end = i + 5;
            sum = top = 0;
        }
    }
    if (beg <= len && top >= topcut) {
        for (k = beg; k <= end && k <= len; k++)
            hit[k] = hit[k - off] = 1;
    }
}
}
