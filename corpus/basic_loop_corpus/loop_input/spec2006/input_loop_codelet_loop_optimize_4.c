#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int *uid_luid;
int max_uid_for_loop;
int i;

static int *internal_uid_luid_storage;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB to target ~0.01 sec runtime
    internal_uid_luid_storage = (int*)calloc(data_size, sizeof(int));
    
    if (!internal_uid_luid_storage) {
        exit(1);
    }

    // Initialize with non-zero values except some zeros to trigger condition
    for (size_t idx = 0; idx < data_size; idx++) {
        internal_uid_luid_storage[idx] = (idx % 7 == 0) ? 0 : (idx + 1);
    }

    uid_luid = internal_uid_luid_storage;
    max_uid_for_loop = (int)data_size;

    // Ensure first element is non-zero to avoid reading before start in loop
    if (max_uid_for_loop > 0) {
        uid_luid[0] = 1;
    }
}