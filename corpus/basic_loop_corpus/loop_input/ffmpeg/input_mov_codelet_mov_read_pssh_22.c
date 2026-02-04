#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

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

static uint8_t global_system_id[16] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                                       0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10};

static uint8_t global_data[131072]; // 128KB to target ~0.01s processing

static uint8_t key_id_1[16] = {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
                               0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20};
static uint8_t key_id_2[16] = {0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
                               0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30};
static uint8_t *global_key_ids[2] = {key_id_1, key_id_2};

static AVEncryptionInitInfo node1;
static AVEncryptionInitInfo node2;
static AVEncryptionInitInfo node3;

AVEncryptionInitInfo *info = &node3;
AVEncryptionInitInfo *old_init_info = &node1;

void init_vars() {
    // Initialize data arrays
    memset(global_data, 0xAB, sizeof(global_data));

    // Setup node1
    node1.system_id = global_system_id;
    node1.system_id_size = 16;
    node1.key_ids = global_key_ids;
    node1.num_key_ids = 2;
    node1.key_id_size = 16;
    node1.data = global_data;
    node1.data_size = sizeof(global_data);
    node1.next = &node2;

    // Setup node2
    node2.system_id = global_system_id;
    node2.system_id_size = 16;
    node2.key_ids = global_key_ids;
    node2.num_key_ids = 2;
    node2.key_id_size = 16;
    node2.data = global_data;
    node2.data_size = sizeof(global_data);
    node2.next = NULL;

    // Setup node3 (info)
    node3.system_id = global_system_id;
    node3.system_id_size = 16;
    node3.key_ids = global_key_ids;
    node3.num_key_ids = 2;
    node3.key_id_size = 16;
    node3.data = global_data;
    node3.data_size = sizeof(global_data);
    node3.next = NULL;
}