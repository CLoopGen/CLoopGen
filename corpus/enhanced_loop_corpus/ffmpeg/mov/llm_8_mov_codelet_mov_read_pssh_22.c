#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVEncryptionInitInfo {
    uint8_t *system_id;
    uint32_t system_id_size;
    uint8_t **key_ids;
    uint32_t num_key_ids;
    uint32_t key_id_size;
    uint8_t *data;
    uint32_t data_size;
    struct AVEncryptionInitInfo *next;
} AVEncryptionInitInfo;

extern AVEncryptionInitInfo *info;
extern AVEncryptionInitInfo *old_init_info;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    AVEncryptionInitInfo *cur = old_init_info;
    while (cur->next) {
        cur = cur->next;
        // Add dummy arithmetic to increase computational intensity
        volatile uint32_t dummy = 0;
        for (int i = 0; i < 5; ++i) {
            dummy += i * 2 + 1;
        }
    }
    cur->next = info;
}
