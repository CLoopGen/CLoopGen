#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct vorbis_enc_mapping {
    int submaps;
    int *mux;
    int *floor;
    int *residue;
    int coupling_steps;
    int *magnitude;
    int *angle;
} vorbis_enc_mapping;

static int *g_floor;
static int *g_residue;
vorbis_enc_mapping *mc;
int i;

void init_vars() {
    mc = (vorbis_enc_mapping *)calloc(1, sizeof(vorbis_enc_mapping));
    if (!mc) exit(1);

    size_t data_size = 1 << 20; // ~1MB of data per array
    mc->submaps = data_size;

    g_floor = (int *)calloc(data_size, sizeof(int));
    g_residue = (int *)calloc(data_size, sizeof(int));
    if (!g_floor || !g_residue) exit(1);

    mc->floor = g_floor;
    mc->residue = g_residue;
    mc->mux = NULL;
    mc->magnitude = NULL;
    mc->angle = NULL;
    mc->coupling_steps = 0;
}