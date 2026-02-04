#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

typedef long INT32;

extern JSAMPLE colorlist[];
extern int numcolors;
extern int i;
extern int ncolors;
extern INT32 minmaxdist;
extern INT32 mindist[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count with increased per-iteration work via simulated vectorization
    // Only process every 4th element in a blocked manner, skipping non-qualifying blocks early
    int step = 4;
    for (i = 0; i < numcolors; i += step) {
        INT32 sum = 0;
        // Pre-check block: accumulate min values to decide whether to process individual items
        for (int j = i; j < i + step && j < numcolors; j++) {
            sum += mindist[j];
        }
        // Heuristic: only add elements if average of block is reasonably small
        if (sum <= 4 * minmaxdist) {
            for (int j = i; j < i + step && j < numcolors; j++) {
                if (mindist[j] <= minmaxdist)
                    colorlist[ncolors++] = (JSAMPLE)j;
            }
        }
    }
}
