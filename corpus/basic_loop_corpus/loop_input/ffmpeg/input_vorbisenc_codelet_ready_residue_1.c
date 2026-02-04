#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct vorbis_enc_residue {
    int type;
    int begin;
    int end;
    int partition_size;
    int classifications;
    int classbook;
    int8_t (*books)[8];
    float (*maxes)[2];
} vorbis_enc_residue;

static float (*g_maxes_data)[2];
static vorbis_enc_residue g_rc;

vorbis_enc_residue *rc = &g_rc;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~512MB of float pairs -> 64M elements
    const int num_elements = data_size / sizeof(float[2]);
    
    g_maxes_data = aligned_alloc(32, num_elements * sizeof(float[2]));
    if (!g_maxes_data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < num_elements; idx++) {
        g_maxes_data[idx][0] = 0.0f;
        g_maxes_data[idx][1] = 0.0f;
    }

    g_rc.classifications = num_elements;
    g_rc.maxes = g_maxes_data;
    g_rc.books = NULL;
    g_rc.type = 0;
    g_rc.begin = 0;
    g_rc.end = 0;
    g_rc.partition_size = 0;
    g_rc.classbook = 0;
}