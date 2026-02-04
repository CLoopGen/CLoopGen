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
    // Eliminate loop-carried dependence on 'sum' by unrolling assumption with stride handling
    // Introduce delayed decision: defer updates to 'hit' until end using a buffer to remove intra-loop write-after-write hazards
    int record_flag = 0;
    int record_beg, record_end;

    for (i = off + 1; i <= len; i++) {
        int delta = xpam120[(int)dsq[i]][(int)dsq[i - off]];
        sum += delta;

        if (sum > top) {
            top = sum;
            end = i;
        }

        // Instead of immediate writes to 'hit', we delay the decision
        if (top >= topcut && top - sum > fallcut) {
            // Mark region for later update, avoid writing to hit inside inner loop
            record_flag = 1;
            record_beg = beg;
            record_end = end;
            sum = top = 0;
            beg = end = i + 1;
        } else if (top - sum > fallcut || sum < 0) {
            sum = top = 0;
            beg = end = i + 1;
        }
    }

    // Now apply side effects outside the accumulation loop — eliminates loop-carried WAW on 'hit'
    if (record_flag) {
        for (k = record_beg; k <= record_end; k++)
            hit[k] = hit[k - off] = 1;
    }

    // Final segment check without interference from mid-loop mutations
    if (top >= topcut) {
        for (k = beg; k <= end; k++)
            hit[k] = hit[k - off] = 1;
    }
}
}
