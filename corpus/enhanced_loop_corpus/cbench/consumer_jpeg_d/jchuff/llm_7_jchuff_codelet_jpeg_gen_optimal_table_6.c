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



void loop() {
    for (;;) {
        long local_min_val = 1000000000L;
        long second_min_val = 1000000000L;
        int candidate1 = -1;
        int candidate2 = -1;
        
        // Combined single-pass search to reduce loop-carried dependencies
        // Eliminates two separate loops, introducing tighter data dependency (RAW)
        for (i = 0; i <= 256; i++) {
            if (!freq[i]) continue;
            
            if (freq[i] <= local_min_val) {
                second_min_val = local_min_val;
                candidate2 = candidate1;
                local_min_val = freq[i];
                candidate1 = i;
            } else if (freq[i] <= second_min_val) {
                second_min_val = freq[i];
                candidate2 = i;
            }
        }
        
        c1 = candidate1;
        c2 = candidate2;
        
        if (c2 < 0)
            break;
        
        // Immediate update without intermediate variables to create WAW
        freq[c1] = freq[c1] + freq[c2];
        freq[c2] = 0;
        
        // Increment codesize in a sequential manner enforcing RAW dependency
        codesize[c1] = codesize[c1] + 1;
        
        // Simulate the while(others[c1] >= 0) loop using bounded iteration
        for (int depth = 0, current = others[c1]; depth <= 256 && current >= 0; depth++) {
            codesize[current]++;
            current = others[current];
        }
        
        others[c1] = c2;
        
        codesize[c2] = codesize[c2] + 1;
        
        // Simulate the while(others[c2] >= 0) loop
        for (int depth = 0, current = others[c2]; depth <= 256 && current >= 0; depth++) {
            codesize[current]++;
            current = others[current];
        }
    }
}
