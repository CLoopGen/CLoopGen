#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *uni;
extern int unilen;
extern int i;
extern char *asctmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices;
    int j;
    // Simulate indirect access via an index array (assume indices is precomputed)
    for (j = 0; j < unilen; j += 2) {
        int pos = j;
        asctmp[pos / 2] = uni[pos];
    }
}
