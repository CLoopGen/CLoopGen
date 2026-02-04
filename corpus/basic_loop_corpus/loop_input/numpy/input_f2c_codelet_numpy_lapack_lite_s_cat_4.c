#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int ftnlen;

char *lp;
char *rpp[1024];
ftnlen rnp[1024];
ftnlen ll;
ftnlen i;
ftnlen nc;
char *rp;
ftnlen n = 1024;

static char *buffer_pool;
static char **temp_rpp;
static ftnlen *temp_rnp;
static char *lp_base;
static size_t total_data_size = 0;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64 MB of data
    n = 1024;
    ll = target_bytes / n + 32; // Distribute total across n segments with padding

    // Allocate base buffer for lp (output)
    lp_base = (char*)calloc(ll * n, sizeof(char));
    if (!lp_base) exit(1);
    lp = lp_base;

    // Allocate temporary arrays to manage rpp and rnp before assigning to externs
    temp_rpp = (char**)calloc(n, sizeof(char*));
    temp_rnp = (ftnlen*)calloc(n, sizeof(ftnlen));
    if (!temp_rpp || !temp_rnp) exit(1);

    // Allocate a shared buffer pool for all source strings
    total_data_size = 0;
    for (i = 0; i < n; ++i) {
        // Vary length per segment to simulate realistic variation
        temp_rnp[i] = (target_bytes / n) / 32 + (i % 500); // avg ~1-2KB each
        total_data_size += temp_rnp[i];
    }

    buffer_pool = (char*)calloc(total_data_size, sizeof(char));
    if (!buffer_pool) exit(1);

    char *buf_ptr = buffer_pool;
    for (i = 0; i < n; ++i) {
        temp_rpp[i] = buf_ptr;
        // Initialize with non-zero pattern to avoid accidental assumptions
        for (nc = 0; nc < temp_rnp[i]; ++nc) {
            buf_ptr[nc] = (char)(33 + (i * 7 + nc * 13) % 94); // printable ASCII
        }
        buf_ptr += temp_rnp[i];
    }

    // Now assign to the actual external variables
    for (i = 0; i < n; ++i) {
        rpp[i] = temp_rpp[i];
        rnp[i] = temp_rnp[i];
    }

    // Ensure ll is large enough to hold all copies (simulate prior state)
    ll = target_bytes; // initial available space

    // Free temporaries not needed after init
    free(temp_rpp);
    free(temp_rnp);
}

// Cleanup function to prevent memory leaks (not called here but good practice)
void cleanup_vars() {
    free(lp_base);
    free(buffer_pool);
}