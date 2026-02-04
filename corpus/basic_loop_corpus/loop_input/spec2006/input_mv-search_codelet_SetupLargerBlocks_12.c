#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int max_pos;
int pos;
int *_o;
int *_i;
int *_j;

void init_vars() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    size_t data_size = 64 * 1024 * 1024;
    max_pos = data_size / sizeof(int);
    _i = (int *)aligned_alloc(32, data_size);
    _j = (int *)aligned_alloc(32, data_size);
    _o = (int *)aligned_alloc(32, data_size);

    for (int i = 0; i < max_pos; i++) {
        _i[i] = rand();
        _j[i] = rand();
        _o[i] = 0;
    }

    do {
        gettimeofday(&end, NULL);
        long seconds = end.tv_sec - start.tv_sec;
        long microseconds = seconds * 1000000 + (end.tv_usec - start.tv_usec);
        if (microseconds >= 10000) break;

        for (pos = 0; pos < max_pos; pos++)
            _o[pos] = _i[pos] + _j[pos];
    } while (1);
}