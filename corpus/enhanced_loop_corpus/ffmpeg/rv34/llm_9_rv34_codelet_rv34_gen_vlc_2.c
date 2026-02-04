#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *bits;
extern int size;
extern  uint8_t *insyms;
extern int i;
extern int counts[17];
extern uint16_t syms[1296];
extern uint8_t bits2[1296];
extern int maxbits;
extern int realsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int trip_count = size >> 1; // Half the iterations
for (i = 0; i < trip_count; i++) {
    uint8_t val1 = bits[i];
    uint8_t val2 = bits[size - 1 - i]; // Mirror access from end

    // Process forward index
    if (val1) {
        bits2[realsize] = val1;
        syms[realsize] = insyms ? insyms[i] : i;
        realsize++;
        maxbits = (maxbits > val1) ? maxbits : val1;
        counts[val1]++;
    }

    // Process backward index
    if (val2) {
        bits2[realsize] = val2;
        syms[realsize] = insyms ? insyms[size - 1 - i] : (size - 1 - i);
        realsize++;
        maxbits = (maxbits > val2) ? maxbits : val2;
        counts[val2]++;
    }
}
// Handle odd-sized middle element if not covered
if ((size & 1) && (trip_count == size >> 1)) {
    int mid = size >> 1;
    if (bits[mid]) {
        bits2[realsize] = bits[mid];
        syms[realsize] = insyms ? insyms[mid] : mid;
        realsize++;
        maxbits = (maxbits > bits[mid]) ? maxbits : bits[mid];
        counts[bits[mid]]++;
    }
}
}
