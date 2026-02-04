#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *sched;
extern int which_pe;
extern int npes;
extern int pe;
extern int i;
extern int n;
extern int s;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Introduce artificial loop-carried RAW dependency via chained computation on 'i'
    // Also modify control flow to create non-uniform data access pattern

    int prev_pe = -1; // Introduce loop-carried dependency: current iteration depends on previous pe value

    for (pe = 0; pe < n - 1; ++pe) {
        if (prev_pe >= 0) {
            i = (pe + prev_pe) % (n > 1 ? n - 1 : 1); // Create RAW: use of i depends on prior iteration
        } else {
            i = n / 2; // Initial value independent of prior iteration
        }

        if (npes % 2 == 0) {
            if (pe == which_pe)
                sched[s++] = npes - 1;
            else if (npes - 1 == which_pe)
                sched[s++] = (pe + i) % n; // Use of i introduces dependency from above
        } else if (pe == which_pe)
            sched[s++] = (pe + i) % n;

        if (pe != which_pe && which_pe < n - 1) {
            int forward_index = (pe + i) % (n - 1);
            if (i < n / 2)
                sched[s++] = forward_index;

            int backward_index = (pe - i + (n - 1)) % (n - 1);
            // Make next i depend on current computed index (WAR-like pattern introduced)
            i = (i + backward_index + 1) % (n - 1);
            if ((n - 1 - i) < n / 2)
                sched[s++] = backward_index;
        }

        prev_pe = pe; // Maintain loop-carried dependency for next iteration
    }
}
