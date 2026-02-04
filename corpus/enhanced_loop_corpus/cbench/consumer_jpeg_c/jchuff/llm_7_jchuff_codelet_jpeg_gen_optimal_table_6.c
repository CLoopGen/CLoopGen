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
    int done = 0;
    for (; !done;) {
        c1 = -1;
        v = 1000000000L;

        // Combined search with early termination hints (introduces WAR dependency via speculative update)
        for (i = 0; i <= 256; i++) {
            long fi = freq[i];
            int valid = fi && (fi < v || (fi == v && i < c1));
            c1 = valid ? i : c1;
            v = valid ? fi : v;
        }

        c2 = -1;
        long v2 = 1000000000L;

        // Eliminate conditional data hazard by using arithmetic masking (removes branching on c1)
        for (i = 0; i <= 256; i++) {
            long fi = freq[i];
            long mask = (fi > 0) & (fi <= v2) & (i != c1);
            v2 = mask ? fi : v2;
            c2 = mask ? i : c2;
        }

        if (c2 < 0) {
            done = 1;
            continue;
        }

        // Immediate compound update to create WAW dependency intentionally
        freq[c1] = freq[c1] + freq[c2];
        freq[c2] = 0;

        codesize[c1] = codesize[c1] + 1;
        codesize[c2] = codesize[c2] + 1;

        // Flatten the chain updates into a single forward sweep without recursion or nested loops
        // Simulate traversal using direct indexing with no backward dependencies
        int stack[257], top = 0;
        if (others[c1] >= 0) stack[top++] = others[c1];
        if (others[c2] >= 0) stack[top++] = others[c2];

        for (i = 0; i < top; i++) {
            int node = stack[i];
            codesize[node]++;
            if (others[node] >= 0 && i < 256) { // bound safety
                stack[top++] = others[node];
            }
        }

        others[c1] = c2;
    }
}
