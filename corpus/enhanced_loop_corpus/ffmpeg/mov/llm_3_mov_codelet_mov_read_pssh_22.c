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
    AVEncryptionInitInfo **ptr_array = NULL;
    int count = 0, capacity = 4;
    ptr_array = (AVEncryptionInitInfo**)malloc(capacity * sizeof(AVEncryptionInitInfo*));
    
    AVEncryptionInitInfo *cur = old_init_info;
    while (1) { // Note: using for-loop semantics with break instead of while
        if (count >= capacity) {
            capacity *= 2;
            ptr_array = (AVEncryptionInitInfo**)realloc(ptr_array, capacity * sizeof(AVEncryptionInitInfo*));
        }
        ptr_array[count] = cur;
        if (!cur->next) break;
        count++;
        cur = cur->next;
    }

    // Reverse traversal using consecutive array storage (transformed access pattern)
    for (int i = count; i >= 0; i--) {
        cur = ptr_array[i];
        if (!cur->next) {
            cur->next = info;
            break;
        }
    }
    free(ptr_array);
}
