#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

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

ML_COMMON_PKCS8_FMT_PREF *fmt_slots;
ML_COMMON_PKCS8_FMT_PREF *slot;
ML_COMMON_PKCS8_FMT *p8fmt;
uint8_t *pos;
int len;
uint32_t magic;

static ML_COMMON_PKCS8_FMT fmt_array[1024];
static ML_COMMON_PKCS8_FMT_PREF fmt_pref_array[1024];
static uint8_t data_buffer[524288]; // ~512KB

void init_vars() {
    for (int i = 0; i < 1024; ++i) {
        fmt_array[i].p8_name = "dummy";
        fmt_array[i].p8_bytes = 32;
        fmt_array[i].p8_shift = (i == 512) ? sizeof(uint32_t) : rand() % 5;
        fmt_array[i].p8_magic = (i == 512) ? 0x12345678 : rand();
        fmt_array[i].seed_magic = rand();
        fmt_array[i].seed_offset = rand() % 256;
        fmt_array[i].seed_length = rand() % 32;
        fmt_array[i].priv_magic = rand();
        fmt_array[i].priv_offset = rand() % 256;
        fmt_array[i].priv_length = rand() % 128;
        fmt_array[i].pub_offset = rand() % 256;
        fmt_array[i].pub_length = rand() % 128;

        fmt_pref_array[i].fmt = &fmt_array[i];
        fmt_pref_array[i].pref = rand();
    }

    fmt_slots = fmt_pref_array;
    p8fmt = NULL;
    slot = NULL;
    pos = data_buffer + sizeof(data_buffer) - 1;
    len = 32;
    magic = 0x12345678;

    for (size_t i = 0; i < sizeof(data_buffer); ++i) {
        data_buffer[i] = rand() & 0xFF;
    }
}