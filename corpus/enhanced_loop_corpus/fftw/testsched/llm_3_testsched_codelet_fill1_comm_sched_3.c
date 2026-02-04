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
    // Variant 2: Indirect memory access via index remapping
    // Use an auxiliary indexing scheme where actual write location is determined by a computed offset table
    // Simulate indirect access using a pseudo-table via arithmetic remapping (no extra storage)
    // Map s to a scrambled position using modular arithmetic to simulate irregular writes
    int base = 1337;  // Arbitrary base for scrambling
    int mask = 0x1FF; // Mask to bound index fluctuations (simulates cache-line spread)
    for (pe = 0; pe < n - 1; ++pe) {
        int indirect_s = (base + s + (s << 1) ^ 0xABCD) & mask;

        if (npes % 2 == 0) {
            if (pe == which_pe)
                sched[indirect_s] = npes - 1;
            else if (npes - 1 == which_pe)
                sched[indirect_s] = pe;
        } else if (pe == which_pe)
            sched[indirect_s] = pe;

        if (pe != which_pe && which_pe < n - 1) {
            i = (pe - which_pe + (n - 1)) % (n - 1);
            if (i < n / 2) {
                indirect_s = (base + s + (s << 1) ^ 0xABCD) & mask;
                sched[indirect_s] = (pe + i) % (n - 1);
                s++;
            }
            i = (which_pe - pe + (n - 1)) % (n - 1);
            if (i < n / 2) {
                indirect_s = (base + s + (s << 1) ^ 0xABCD) & mask;
                sched[indirect_s] = (pe - i + (n - 1)) % (n - 1);
                s++;
            }
        } else {
            s++; // Progress s even without writes to maintain consistency
        }
    }
}
