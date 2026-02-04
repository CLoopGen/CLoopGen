#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

size_t size1;
size_t size2;
size_t i;
size_t j;

static double get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec * 1e-6;
}

void init_vars() {
    double start = get_time();
    
    const size_t target_ns = 10000000; // 10 ms in ns
    size_t temp_size1 = 10000;
    size_t temp_size2 = 10000;
    
    int warmup_done = 0;
    while (1) {
        size1 = temp_size1;
        size2 = temp_size2;
        
        double loop_start = get_time();
        for (i = 0; i < size1; i++) {
            for (j = 0; j < size2; j++) {
            }
        }
        double loop_end = get_time();
        double elapsed_ms = (loop_end - loop_start) * 1000;
        
        if (!warmup_done) {
            warmup_done = 1;
            if (elapsed_ms < 1.0) {
                temp_size1 *= 10;
                temp_size2 *= 10;
                continue;
            }
        }
        
        if (elapsed_ms >= 10.0) {
            break;
        } else if (elapsed_ms < 5.0) {
            temp_size1 = (temp_size1 * 120) / 100;
            temp_size2 = (temp_size2 * 120) / 100;
        } else {
            break;
        }
        
        if (temp_size1 > 10000000 || temp_size2 > 10000000) break;
    }
}