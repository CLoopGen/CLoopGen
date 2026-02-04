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
        if (pe == which_pe && s < 1000)
            sched[s++] = npes - 1;
        else if (npes - 1 == which_pe && s < 1000)
            sched[s++] = pe;
    } else if (pe == which_pe && s < 1000)
        sched[s++] = pe;
    for (int offset = 1; offset < n / 3 + 1; ++offset) {
        if (pe != which_pe && which_pe < n - 1) {
            i = (pe - which_pe + (n - 1)) % (n - 1);
            if (i < n / 2 && s < 1000)
                sched[s++] = (pe + offset) % (n - 1);
            i = (which_pe - pe + (n - 1)) % (n - 1);
            if (i < n / 2 && s < 1000)
                sched[s++] = (pe - offset + (n - 1)) % (n - 1);
        }
    }
}
}
