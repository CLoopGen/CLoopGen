#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

void **d;
void **p;
void **s;
int nb_samples;
int channels;
int n;
int c;

#define DEFAULT_DATA_SIZE (128 << 20) // 128 MB target

void init_vars() {
    channels = 8;
    nb_samples = DEFAULT_DATA_SIZE / sizeof(float) / channels;
    
    s = malloc(channels * sizeof(void*));
    d = malloc(channels * sizeof(void*));
    p = malloc(channels * sizeof(void*));
    
    if (!s || !d || !p) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    
    for (int i = 0; i < channels; i++) {
        size_t alloc_size = nb_samples * sizeof(float);
        s[i] = malloc(alloc_size);
        d[i] = malloc(alloc_size);
        p[i] = malloc(sizeof(float));
        
        if (!s[i] || !d[i] || !p[i]) {
            fprintf(stderr, "Failed to allocate channel memory\n");
            exit(1);
        }
        
        memset(s[i], 0, alloc_size);
        memset(d[i], 0, alloc_size);
        *(float*)p[i] = 0.0f;
    }
}