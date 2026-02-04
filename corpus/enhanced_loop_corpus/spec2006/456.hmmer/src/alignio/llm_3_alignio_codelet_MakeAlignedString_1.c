#include <stdio.h>

#include <inttypes.h>

extern char *aseq;
extern int alen;
extern char *ss;
extern char *new;
extern int apos;
extern int rpos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated via alternating forward/backward access)
    // Simulate non-consecutive access by processing from both ends toward center
    int left, right;
    for (left = 0, right = alen - 1, apos = 0, rpos = 0; left <= right; left++, right--) {
        // Left side access
        if (!((aseq[left]) == ' ' || (aseq[left]) == '.' || (aseq[left]) == '_' || (aseq[left]) == '-' || (aseq[left]) == '~')) {
            new[left] = ss[rpos];
            rpos++;
        } else {
            new[left] = '.';
        }

        // Avoid double processing at the center
        if (left != right) {
            if (!((aseq[right]) == ' ' || (aseq[right]) == '.' || (aseq[right]) == '_' || (aseq[right]) == '-' || (aseq[right]) == '~')) {
                new[right] = ss[rpos];
                rpos++;
            } else {
                new[right] = '.';
            }
        }
    }
    // Finalize apos to reflect full traversal (for consistency with original)
    apos = alen;
}
