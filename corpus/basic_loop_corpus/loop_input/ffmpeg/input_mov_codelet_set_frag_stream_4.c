#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct AVSubsampleEncryptionInfo {
    unsigned int bytes_of_clear_data;
    unsigned int bytes_of_protected_data;
} AVSubsampleEncryptionInfo;

typedef struct AVEncryptionInfo {
    uint32_t scheme;
    uint32_t crypt_byte_block;
    uint32_t skip_byte_block;
    uint8_t *key_id;
    uint32_t key_id_size;
    uint8_t *iv;
    uint32_t iv_size;
    AVSubsampleEncryptionInfo *subsamples;
    uint32_t subsample_count;
} AVEncryptionInfo;

typedef struct MOVEncryptionIndex {
    unsigned int nb_encrypted_samples;
    AVEncryptionInfo **encrypted_samples;
    uint8_t *auxiliary_info_sizes;
    size_t auxiliary_info_sample_count;
    uint8_t auxiliary_info_default_size;
    uint64_t *auxiliary_offsets;
    size_t auxiliary_offsets_count;
} MOVEncryptionIndex;

typedef struct MOVFragmentStreamInfo {
    int id;
    int64_t sidx_pts;
    int64_t first_tfra_pts;
    int64_t tfdt_dts;
    int64_t next_trun_dts;
    int64_t index_entry;
    MOVEncryptionIndex *encryption_index;
} MOVFragmentStreamInfo;

typedef struct MOVFragmentIndexItem {
    int64_t moof_offset;
    int headers_read;
    int current;
    int nb_stream_info;
    MOVFragmentStreamInfo *stream_info;
} MOVFragmentIndexItem;

int id = 1000;
int i = 0;
MOVFragmentIndexItem *item = NULL;

static AVSubsampleEncryptionInfo *g_subsamples = NULL;
static uint8_t *g_key_id = NULL;
static uint8_t *g_iv = NULL;
static AVEncryptionInfo **g_encrypted_samples = NULL;
static uint8_t *g_auxiliary_info_sizes = NULL;
static uint64_t *g_auxiliary_offsets = NULL;
static MOVEncryptionIndex *g_encryption_index = NULL;
static MOVFragmentStreamInfo *g_stream_info = NULL;

void init_vars() {
    // Allocate stream info array: aim for ~64MB to ensure loop runtime around 0.01s
    // Each MOVFragmentStreamInfo is about 56 bytes, so 64MB / 56 ~ 1.17M entries
    const int num_streams = 1200000;  // ~67.2 MB
    g_stream_info = (MOVFragmentStreamInfo*)calloc(num_streams, sizeof(MOVFragmentStreamInfo));
    if (!g_stream_info) exit(1);

    // Set target ID near the end to force loop to run long enough
    id = 999999;
    for (int idx = 0; idx < num_streams; idx++) {
        g_stream_info[idx].id = idx;
        g_stream_info[idx].encryption_index = NULL;
    }

    // Only allocate encryption index for one item to save memory
    g_encryption_index = (MOVEncryptionIndex*)calloc(1, sizeof(MOVEncryptionIndex));
    if (!g_encryption_index) exit(1);
    g_encryption_index->nb_encrypted_samples = 0;
    g_encryption_index->encrypted_samples = NULL;
    g_encryption_index->auxiliary_info_sizes = NULL;
    g_encryption_index->auxiliary_info_sample_count = 0;
    g_encryption_index->auxiliary_info_default_size = 0;
    g_encryption_index->auxiliary_offsets = NULL;
    g_encryption_index->auxiliary_offsets_count = 0;

    // Assign valid encryption index to the matching stream
    g_stream_info[id].encryption_index = g_encryption_index;

    // Initialize item
    item = (MOVFragmentIndexItem*)malloc(sizeof(MOVFragmentIndexItem));
    if (!item) exit(1);
    item->moof_offset = 0;
    item->headers_read = 0;
    item->current = -1;
    item->nb_stream_info = num_streams;
    item->stream_info = g_stream_info;
}