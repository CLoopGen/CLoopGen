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
    // Variant 1: Strided Memory Access Pattern
    // Instead of incrementing 's' consecutively, write to every second location to create a strided access pattern in sched.
    int stride = 2; // Access every second element
    for (pe = 0; pe < n - 1; ++pe) {
        if (npes % 2 == 0) {
            if (pe == which_pe)
                sched[s * stride] = npes - 1, s++;
            else if (npes - 1 == which_pe)
                sched[s * stride] = pe, s++;
        } else if (pe == which_pe)
            sched[s * stride] = pe, s++;
        if (pe != which_pe && which_pe < n - 1) {
            i = (pe - which_pe + (n - 1)) % (n - 1);
            if (i < n / 2)
                sched[s * stride] = (pe + i) % (n - 1), s++;
            i = (which_pe - pe + (n - 1)) % (n - 1);
            if (i < n / 2)
                sched[s * stride] = (pe - i + (n - 1)) % (n - 1), s++;
        }
    }
}
