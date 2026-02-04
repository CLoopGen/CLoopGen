#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long freq[];
extern int codesize[257];
extern int others[257];
extern int c1;
extern int c2;
extern int i;
extern int num_nz_symbols;
extern long v;
extern long v2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    while (1) {
        c1 = -1;
        c2 = -1;
        v = 1000000000L;
        v2 = 1000000000L;
        int pair_count = 0;
        for (i = 0; i < num_nz_symbols && pair_count < 2; i++) {
            if (freq[i] >= 1000000001L) continue;
            if (c1 == -1 || freq[i] < v) {
                c2 = c1;
                v2 = v;
                c1 = i;
                v = freq[i];
                pair_count++;
            } else if (c2 == -1 || freq[i] < v2) {
                c2 = i;
                v2 = freq[i];
                pair_count++;
            }
        }
        if (c2 == -1) break;

        freq[c1] += freq[c2];
        freq[c2] = 1000000001L;

        int update_index = c1;
        for (int step = 0; step < 5 && update_index >= 0; step++) {
            codesize[update_index]++;
            update_index = others[update_index];
        }

        others[c1] = c2;

        update_index = c2;
        for (int step = 0; step < 5 && update_index >= 0; step++) {
            codesize[update_index]++;
            update_index = others[update_index];
        }
    }
}
