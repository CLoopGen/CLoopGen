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
OPJ_UINT32 i;
OPJ_UINT32 cblk_len;

static opj_tcd_seg_data_chunk_t *chunks_data;
static OPJ_BYTE **chunk_data_pointers;
static const OPJ_UINT32 target_total_size = 64 * 1024 * 1024;
static const OPJ_UINT32 chunk_size = 8192;

void init_vars() {
    OPJ_UINT32 num_chunks = target_total_size / chunk_size;

    chunk_data_pointers = (OPJ_BYTE**)calloc(num_chunks, sizeof(OPJ_BYTE*));
    chunks_data = (opj_tcd_seg_data_chunk_t*)calloc(num_chunks, sizeof(opj_tcd_seg_data_chunk_t));

    for (OPJ_UINT32 idx = 0; idx < num_chunks; ++idx) {
        chunk_data_pointers[idx] = (OPJ_BYTE*)calloc(chunk_size, 1);
        chunks_data[idx].data = chunk_data_pointers[idx];
        chunks_data[idx].len = chunk_size;
    }

    cblk = (opj_tcd_cblk_dec_t*)calloc(1, sizeof(opj_tcd_cblk_dec_t));
    cblk->chunks = chunks_data;
    cblk->numchunks = num_chunks;
    cblk->numchunksalloc = num_chunks;

    i = 0;
    cblk_len = 0;
}