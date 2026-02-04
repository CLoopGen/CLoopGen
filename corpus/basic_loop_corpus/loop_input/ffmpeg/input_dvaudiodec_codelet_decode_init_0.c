#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DVAudioContext {
    int block_size;
    int is_12bit;
    int is_pal;
    int16_t shuffle[2000];
} DVAudioContext;

DVAudioContext *s;
int i;

void init_vars() {
    s = (DVAudioContext*)malloc(sizeof(DVAudioContext));
    if (!s) exit(1);
    
    s->block_size = 0;
    s->is_12bit = 0;
    s->is_pal = 1; // Ensures a = 18, b = 54
}