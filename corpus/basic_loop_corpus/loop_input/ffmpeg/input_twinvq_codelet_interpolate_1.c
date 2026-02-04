#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/time.h>

float *out;
float v2;
int size;
int i;
float step;

void init_vars() {
    struct timeval tv_start, tv_end;
    gettimeofday(&tv_start, NULL);
    
    size = 1;
    const int max_size = 256 * (1 << 20) / sizeof(float); // ~256MB limit
    const float target_time = 0.01f; // 10ms target
    
    while (size <= max_size) {
        float *temp_out = (float*)malloc(size * sizeof(float));
        if (!temp_out) break;
        
        float temp_v2 = 1.0f;
        float temp_step = 0.5f;
        
        gettimeofday(&tv_start, NULL);
        for (i = 0; i < size; i++) {
            temp_v2 += temp_step;
            temp_out[i] = temp_v2;
        }
        gettimeofday(&tv_end, NULL);
        
        float elapsed = (tv_end.tv_sec - tv_start.tv_sec) + 
                       (tv_end.tv_usec - tv_start.tv_usec) / 1e6f;
        
        free(temp_out);
        
        if (elapsed >= target_time) break;
        
        size *= 2;
    }
    
    if (size > max_size) size = max_size;
    if (size < 1000) size = 1000;
    
    out = (float*)malloc(size * sizeof(float));
    if (!out) {
        size = 1000;
        out = (float*)malloc(size * sizeof(float));
    }
    
    v2 = 1.0f;
    step = 0.5f;
}