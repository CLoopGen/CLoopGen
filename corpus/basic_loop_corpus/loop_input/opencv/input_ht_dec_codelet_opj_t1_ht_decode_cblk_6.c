#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;
typedef int OPJ_BOOL;
typedef unsigned char OPJ_BYTE;

typedef struct opj_tcd_seg {
    OPJ_UINT32 len;
    OPJ_UINT32 numpasses;
    OPJ_UINT32 real_num_passes;
    OPJ_UINT32 maxpasses;
    OPJ_UINT32 numnewpasses;
    OPJ_UINT32 newlen;
} opj_tcd_seg_t;

typedef struct opj_tcd_seg_data_chunk {
    OPJ_BYTE *data;
    OPJ_UINT32 len;
} opj_tcd_seg_data_chunk_t;

typedef struct opj_tcd_cblk_dec {
    opj_tcd_seg_t *segs;
    opj_tcd_seg_data_chunk_t *chunks;
    OPJ_INT32 x0;
    OPJ_INT32 y0;
    OPJ_INT32 x1;
    OPJ_INT32 y1;
    OPJ_UINT32 Mb;
    OPJ_UINT32 numbps;
    OPJ_UINT32 numlenbits;
    OPJ_UINT32 numnewpasses;
    OPJ_UINT32 numsegs;
    OPJ_UINT32 real_num_segs;
    OPJ_UINT32 m_current_max_segs;
    OPJ_UINT32 numchunks;
    OPJ_UINT32 numchunksalloc;
    OPJ_INT32 *decoded_data;
    OPJ_BOOL corrupted;
} opj_tcd_cblk_dec_t;

opj_tcd_cblk_dec_t *cblk;
OPJ_UINT32 cblk_len = 0;
OPJ_UINT32 i;

static opj_tcd_seg_data_chunk_t* chunks_array = NULL;
static OPJ_BYTE** data_pointers = NULL;

void init_vars() {
    const size_t target_time_ns = 10000000; // ~10 ms
    const size_t avg_chunk_size = 1024;
    const OPJ_UINT32 estimated_chunks = (target_time_ns / 1) / avg_chunk_size;
    const OPJ_UINT32 numchunks = (estimated_chunks > 100000) ? 100000 : 
                                 (estimated_chunks < 1000) ? 1000 : estimated_chunks;

    data_pointers = (OPJ_BYTE**)calloc(numchunks, sizeof(OPJ_BYTE*));
    chunks_array = (opj_tcd_seg_data_chunk_t*)calloc(numchunks, sizeof(opj_tcd_seg_data_chunk_t));

    for (OPJ_UINT32 idx = 0; idx < numchunks; ++idx) {
        OPJ_UINT32 chunk_len = 512 + (idx % 512);
        OPJ_BYTE* data = (OPJ_BYTE*)malloc(chunk_len * sizeof(OPJ_BYTE));
        data_pointers[idx] = data;
        chunks_array[idx].data = data;
        chunks_array[idx].len = chunk_len;
    }

    cblk = (opj_tcd_cblk_dec_t*)malloc(sizeof(opj_tcd_cblk_dec_t));
    cblk->chunks = chunks_array;
    cblk->numchunks = numchunks;
    cblk->numchunksalloc = numchunks;
    cblk->x0 = 0;
    cblk->y0 = 0;
    cblk->x1 = 100;
    cblk->y1 = 100;
    cblk->Mb = 1;
    cblk->numbps = 8;
    cblk->numlenbits = 16;
    cblk->numnewpasses = 1;
    cblk->numsegs = 0;
    cblk->real_num_segs = 0;
    cblk->m_current_max_segs = 0;
    cblk->segs = NULL;
    cblk->decoded_data = NULL;
    cblk->corrupted = 0;

    cblk_len = 0;
    i = 0;
}