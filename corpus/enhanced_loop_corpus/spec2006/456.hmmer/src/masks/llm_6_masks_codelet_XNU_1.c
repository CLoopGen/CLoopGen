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
    int local_sum, local_top;
    local_sum = local_top = 0;
    int temp_beg = beg;
    for (i = off + 1; i <= len; i++) {
        // Introduce local copy to break WAW and WAR dependencies on shared 'sum' and 'top'
        local_sum += xpam120[(int)dsq[i]][(int)dsq[i - off]];
        if (local_sum > local_top) {
            local_top = local_sum;
            end = i;
        }
        // Use updated values only at safe points to reduce loop-carried dependency chain
        if (local_top >= topcut && local_top - local_sum > fallcut) {
            for (k = temp_beg; k <= end; k++)
                hit[k] = hit[k - off] = 1;
            local_sum = local_top = 0;
            temp_beg = end = i + 1;
        } else if (local_top - local_sum > fallcut) {
            local_sum = local_top = 0;
            temp_beg = end = i + 1;
        }
        if (local_sum < 0) {
            temp_beg = end = i + 1;
            local_sum = local_top = 0;
        }
    }
    // Final update to global variables from local accumulators
    sum = local_sum;
    top = local_top;
    if (top >= topcut) {
        for (k = temp_beg; k <= end; k++)
            hit[k] = hit[k - off] = 1;
    }
}
}
