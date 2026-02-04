#include <stdio.h>

#include <inttypes.h>

extern long freq[];
extern int codesize[257];
extern int others[257];
extern int c1;
extern int c2;
extern int i;
extern long v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (;;) {
        c1 = -1;
        v = 1000000000L;
        long temp_freq[257];
        int temp_codesize[257];
        int temp_others[257];

        // Initialize temporaries to remove write-after-read hazards in reduction
        for (i = 0; i <= 256; i++) {
            temp_freq[i] = freq[i];
            temp_codesize[i] = codesize[i];
            temp_others[i] = others[i];
        }

        // First pass: find minimum frequency (c1)
        for (i = 0; i <= 256; i++) {
            if (temp_freq[i] && temp_freq[i] <= v) {
                v = temp_freq[i];
                c1 = i;
            }
        }

        c2 = -1;
        v = 1000000000L;

        // Second pass: find next minimum excluding c1
        for (i = 0; i <= 256; i++) {
            if (temp_freq[i] && temp_freq[i] <= v && i != c1) {
                v = temp_freq[i];
                c2 = i;
            }
        }

        if (c2 < 0)
            break;

        // Update shared state with combined updates to reduce loop-carried dependencies
        temp_freq[c1] += temp_freq[c2];
        temp_freq[c2] = 0;
        temp_codesize[c1]++;
        temp_codesize[c2]++;

        int current = temp_others[c1];
        while (current >= 0) {
            temp_codesize[current]++;
            current = temp_others[current];
        }

        current = temp_others[c2];
        while (current >= 0) {
            temp_codesize[current]++;
            current = temp_others[current];
        }

        temp_others[c1] = c2;

        // Commit updates back to global arrays
        for (i = 0; i <= 256; i++) {
            freq[i] = temp_freq[i];
            codesize[i] = temp_codesize[i];
            others[i] = temp_others[i];
        }
    }
}
