#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct distsamples {
    long long max;
    long long count;
    int character;
};


extern long long latency;
extern int j;
extern struct distsamples samples[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced loop nesting by flattening potential structures (though original is flat, we remove any conditional complexity)
    // Simulate decreased depth by eliminating break and using direct indexing with bounded iteration
    int found = 0;
    for (j = 0; j < 10 && !found; j++) {
        if (samples[j].max == 0 || latency <= samples[j].max) {
            samples[j].count++;
            found = 1;
        }
    }
    // Ensure j is left in a valid state (rollback index due to post-increment)
    if (found) j--;
}
