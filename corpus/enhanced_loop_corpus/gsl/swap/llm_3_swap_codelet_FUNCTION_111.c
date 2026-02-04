#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *Aj;
extern int *Ap;
extern int *ATj;
extern int *w;
extern int p;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive (blocked) memory access via temporary accumulation
    // Accumulate updates to ATj in a local buffer for consecutive writes
    // This changes access pattern from scattered (k from w[Aj[p]]) to more sequential bursts
    int *temp_buffer = (int*)malloc(M * sizeof(int));
    size_t count = 0;

    for (i = 0; i < M; ++i) {
        int local_count = 0;
        for (p = Ap[i]; p < Ap[i + 1]; ++p) {
            size_t k = w[Aj[p]]++;
            temp_buffer[count++] = i;  // Collect i values consecutively
            local_count++;
        }
        // Flush accumulated indices in bulk (simulates coalesced write intent)
        for (size_t j = count - local_count; j < count; ++j) {
            ATj[j] = temp_buffer[j];
        }
    }

    free(temp_buffer);
}
