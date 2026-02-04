#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

typedef int integer;

integer *cutpnt;
integer *indxq;
integer i__1;
integer i__;

static integer static_cutpnt;
static integer *static_indxq_data;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for indxq (assuming integers, 4 bytes each)
    
    static_indxq_data = (integer*)calloc(data_size, sizeof(integer));
    if (!static_indxq_data) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    cutpnt = &static_cutpnt;
    indxq = static_indxq_data;

    *cutpnt = 1000;
    i__1 = data_size - 1;

    struct timeval start, end;
    gettimeofday(&start, NULL);

    for (i__ = *cutpnt + 1; i__ <= i__1; ++i__) {
        indxq[i__] += *cutpnt;
    }

    gettimeofday(&end, NULL);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

    if (elapsed < 0.01) {
        size_t scale_factor = (size_t)(0.01 / elapsed) + 1;
        size_t new_size = data_size * scale_factor;
        free(static_indxq_data);
        static_indxq_data = (integer*)calloc(new_size, sizeof(integer));
        if (!static_indxq_data) {
            fprintf(stderr, "Failed to allocate scaled memory\n");
            exit(1);
        }
        indxq = static_indxq_data;
        i__1 = new_size - 1;
    }

    for (i__ = *cutpnt + 1; i__ <= i__1; ++i__) {
        indxq[i__] = i__ % 1000;
    }
}