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
    // Variant 2: Consecutive (fused index) memory access using a temporary sequential buffer
    // Introduce local accumulation to enable consecutive writes to a temp array, then copy if needed
    // This changes indirect write pattern (ATj[k]) into more predictable sequence via local reordering
    int *temp_buffer = (int*)malloc(sizeof(int) * (Ap[M])); // Allocate temp storage for reordered writes
    if (!temp_buffer) return;

    size_t write_offset = 0;
    for (i = 0; i < M; ++i) {
        for (p = Ap[i]; p < Ap[i + 1]; ++p) {
            size_t k = w[Aj[p]]++;
            temp_buffer[write_offset++] = i;  // Consecutive write to temp buffer
        }
    }

    // Flush accumulated data back to ATj with simple copy (consecutive read/write)
    for (size_t idx = 0; idx < write_offset; ++idx) {
        ATj[idx] = temp_buffer[idx];
    }

    free(temp_buffer);
}
