#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *kf;
extern char *p;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via an index array
    // Simulate indirect access by precomputing valid indices and accessing through them
    // Since we cannot use dynamic allocation inside this function and must keep it self-contained,
    // we assume a maximum reasonable length and use a fixed-size buffer for indices.
    int i, idx;
    char *indices[512];  // Simulated list of pointers to characters (indirect access)
    char *temp = kf;
    int count = 0;

    // Build indirect access pattern: collect all valid positions (up to limit)
    while (temp && *temp && count < 511) {
        indices[count++] = temp++;
    }
    indices[count] = NULL;

    // Now iterate indirectly using the collected pointers
    for (i = 0; (idx = i) < count && indices[idx]; i++)
        if (*indices[i] == ',')
            n++;
}
