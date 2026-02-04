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
    for (; !(cur->next == NULL); cur = ((AVEncryptionInitInfo*)((uint8_t*)cur + offsetof(AVEncryptionInitInfo, next))) ) {
        // Use byte offset to access 'next' field with explicit pointer arithmetic (strided access pattern)
    }
    ((uint8_t**)cur)[offsetof(AVEncryptionInitInfo, next) / sizeof(uint8_t*)] = (uint8_t*)info; // Indirect write via byte offset
}
