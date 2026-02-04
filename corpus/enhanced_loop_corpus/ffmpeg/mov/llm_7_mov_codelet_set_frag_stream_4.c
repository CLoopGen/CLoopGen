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
    int index_entry;
    MOVEncryptionIndex *encryption_index;
} MOVFragmentStreamInfo;

typedef struct MOVFragmentIndexItem {
    int64_t moof_offset;
    int headers_read;
    int current;
    int nb_stream_info;
    MOVFragmentStreamInfo *stream_info;
} MOVFragmentIndexItem;

extern int id;
extern int i;
extern MOVFragmentIndexItem *item;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_current = -1;
    for (i = 0; i < item->nb_stream_info; i++) {
        int match = (item->stream_info[i].id == id);
        temp_current = match ? i : temp_current;
    }
    item->current = temp_current;
}
