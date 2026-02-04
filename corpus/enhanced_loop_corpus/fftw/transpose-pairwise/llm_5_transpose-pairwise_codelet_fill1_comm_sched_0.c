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
for (pe = 0; pe < n - 1; ++pe) {
    int cond1 = (npes % 2 == 0);
    int cond2 = (pe == which_pe);
    int cond3 = (npes - 1 == which_pe);

    if (cond1) {
        if (cond2) {
            sched[s++] = npes - 1;
        } else if (cond3) {
            sched[s++] = pe;
        }
    } else if (cond2) {
        sched[s++] = pe;
    }

    if (!cond2 && which_pe < n - 1) {
        i = (pe - which_pe + (n - 1)) % (n - 1);
        if (i < n / 2) {
            int target = (pe + i) % (n - 1);
            sched[s++] = target;
        }
        i = (which_pe - pe + (n - 1)) % (n - 1);
        if (i < n / 2) {
            int target = (pe - i + (n - 1)) % (n - 1);
            sched[s++] = target;
        }
    }
}
}
