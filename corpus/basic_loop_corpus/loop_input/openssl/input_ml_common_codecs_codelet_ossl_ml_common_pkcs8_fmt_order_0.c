#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef struct {
    const char *p8_name;
    size_t p8_bytes;
    int p8_shift;
    uint32_t p8_magic;
    uint16_t seed_magic;
    size_t seed_offset;
    size_t seed_length;
    uint32_t priv_magic;
    size_t priv_offset;
    size_t priv_length;
    size_t pub_offset;
    size_t pub_length;
} ML_COMMON_PKCS8_FMT;

typedef struct {
    const ML_COMMON_PKCS8_FMT *fmt;
    int pref;
} ML_COMMON_PKCS8_FMT_PREF;

#define ARRAY_SIZE 6

static ML_COMMON_PKCS8_FMT p8fmt_data[ARRAY_SIZE];
ML_COMMON_PKCS8_FMT *p8fmt = p8fmt_data;
ML_COMMON_PKCS8_FMT_PREF *ret;
int i;

void init_vars() {
    // Allocate ret array
    ret = (ML_COMMON_PKCS8_FMT_PREF*)calloc(ARRAY_SIZE, sizeof(ML_COMMON_PKCS8_FMT_PREF));
    
    // Initialize p8fmt_data with valid values
    for (int idx = 0; idx < ARRAY_SIZE; ++idx) {
        // Create a string for p8_name on heap to avoid const issues
        char* name = (char*)malloc(16);
        snprintf(name, 16, "format_%d", idx);
        
        p8fmt_data[idx].p8_name = name;
        p8fmt_data[idx].p8_bytes = 128 + idx * 16;
        p8fmt_data[idx].p8_shift = idx * 2;
        p8fmt_data[idx].p8_magic = 0x12345678U + idx;
        p8fmt_data[idx].seed_magic = 0xABCDU + idx;
        p8fmt_data[idx].seed_offset = idx * 32;
        p8fmt_data[idx].seed_length = 16 + idx * 8;
        p8fmt_data[idx].priv_magic = 0xCAFEBABEUL + idx;
        p8fmt_data[idx].priv_offset = 512 + idx * 64;
        p8fmt_data[idx].priv_length = 256 + idx * 32;
        p8fmt_data[idx].pub_offset = 1024 + idx * 128;
        p8fmt_data[idx].pub_length = 512 + idx * 64;
    }
}