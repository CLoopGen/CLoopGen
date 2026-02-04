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
for (pe = 0; pe < (n - 1) / 2; ++pe) {
    for (int step = 1; step <= 2; ++step) {
        int target_pe = (pe * 2) + (step - 1);
        if (target_pe >= n - 1) break;

        if (npes % 2 == 0) {
            if (target_pe == which_pe)
                sched[s++] = npes - 1;
            else if (npes - 1 == which_pe)
                sched[s++] = target_pe;
        } else if (target_pe == which_pe)
            sched[s++] = target_pe;

        if (target_pe != which_pe && which_pe < n - 1) {
            i = (target_pe - which_pe + (n - 1)) % (n - 1);
            if (i < n / 4)
                sched[s++] = (target_pe + i) % (n - 1);
            i = (which_pe - target_pe + (n - 1)) % (n - 1);
            if (i < n / 4)
                sched[s++] = (target_pe - i + (n - 1)) % (n - 1);
        }
    }
}
}
