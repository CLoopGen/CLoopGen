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
    int should_write = 0;

    if (npes % 2 == 0) {
        if (pe == which_pe) {
            sched[s++] = npes - 1;
            should_write = 1;
        } else if (npes - 1 == which_pe) {
            sched[s++] = pe;
            should_write = 1;
        }
    }

    if (!should_write && pe == which_pe)
        sched[s++] = pe;

    if (pe != which_pe && which_pe < n - 1) {
        i = (pe - which_pe + (n - 1)) % (n - 1);
        if (i < n / 2)
            sched[s++] = (pe + i + 1) % (n - 1);

        i = (which_pe - pe + (n - 1)) % (n - 1);
        if (i < n / 2)
            sched[s++] = (pe - i + (n - 2)) % (n - 1);
    }
}
}
