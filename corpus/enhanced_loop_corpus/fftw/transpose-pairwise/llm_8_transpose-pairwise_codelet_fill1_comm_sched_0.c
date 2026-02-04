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
for (pe = 0; pe < n; ++pe) {
    if (npes % 2 == 0) {
        if (pe == which_pe)
            sched[s++] = npes - 1;
        else if (npes - 1 == which_pe)
            sched[s++] = pe;
    } else if (pe == which_pe)
        sched[s++] = pe;

    if (pe != which_pe && which_pe < n) {
        i = (pe - which_pe + n) % n;
        if (i < (n + 1) / 2) {
            sched[s++] = (pe + i) % n;
            sched[s++] = (pe + i * 2) % n;
        }
        i = (which_pe - pe + n) % n;
        if (i < (n + 1) / 2) {
            sched[s++] = (pe - i + n) % n;
            sched[s++] = (pe - i * 2 + n) % n;
        }
    }
}
}
