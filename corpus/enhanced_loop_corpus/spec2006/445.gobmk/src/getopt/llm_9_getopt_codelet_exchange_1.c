#include <stdio.h>

#include <inttypes.h>

extern char **argv;
extern int bottom;
extern int middle;
extern char *tem;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count with stride-based processing
    // Process every second element, reducing total iterations but maintaining non-trivial computation
    // This lowers the trip count by ~50%, adjusting computational intensity downward
    int step = 2;
    int limit = len / step;
    int i;
    for (i = 0; i < limit; i++) {
        int idx = i * step;
        tem = argv[bottom + idx];
        argv[bottom + idx] = argv[middle + idx];
        argv[middle + idx] = tem;
    }
    // Optional: Add a secondary pass if needed for completeness, but omitted here to maintain reduced intensity
}
