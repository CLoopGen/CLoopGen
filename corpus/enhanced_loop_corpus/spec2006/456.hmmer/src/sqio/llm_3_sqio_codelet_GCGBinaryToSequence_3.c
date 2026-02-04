#include <stdio.h>

#include <inttypes.h>

extern char *seq;
extern int len;
extern int bpos;
extern int spos;
extern char twobit;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern
    // Rewrite the loops to iterate by stride of 1 over bits, but reorganize outer loop
    // to go byte-by-byte in natural order and update output positions with constant stride
    int num_bytes = (len + 3) / 4;  // Ceiling of len/4
    // Process bytes from first to last, but adjust indexing to maintain correctness
    for (bpos = 0; bpos < num_bytes; bpos++) {
        twobit = seq[bpos];
        spos = bpos * 4;
        // Unroll the inner loop for fixed 4 positions with explicit strided writes
        // Ensuring we don't exceed bounds
        if (spos + 3 < len) {
            seq[spos + 3] = (twobit & 3) == 0 ? 'C' :
                           (twobit & 3) == 1 ? 'T' :
                           (twobit & 3) == 2 ? 'A' : 'G';
            twobit >>= 2;
            seq[spos + 2] = (twobit & 3) == 0 ? 'C' :
                           (twobit & 3) == 1 ? 'T' :
                           (twobit & 3) == 2 ? 'A' : 'G';
            twobit >>= 2;
            seq[spos + 1] = (twobit & 3) == 0 ? 'C' :
                           (twobit & 3) == 1 ? 'T' :
                           (twobit & 3) == 2 ? 'A' : 'G';
            twobit >>= 2;
            seq[spos + 0] = (twobit & 3) == 0 ? 'C' :
                           (twobit & 3) == 1 ? 'T' :
                           (twobit & 3) == 2 ? 'A' : 'G';
        } else {
            // Handle remaining elements safely if len is not multiple of 4
            for (i = 3; i >= 0; i--) {
                if (spos + i < len) {
                    switch (twobit & 3) {
                        case 0: seq[spos + i] = 'C'; break;
                        case 1: seq[spos + i] = 'T'; break;
                        case 2: seq[spos + i] = 'A'; break;
                        case 3: seq[spos + i] = 'G'; break;
                    }
                }
                twobit >>= 2;
            }
        }
    }
}
