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
        fmt_array[i].p8_shift = 4;
        fmt_array[i].p8_magic = 0x12345678U ^ i;
        fmt_array[i].seed_magic = 0xABCD;
        fmt_array[i].seed_offset = 16;
        fmt_array[i].seed_length = 32;
        fmt_array[i].priv_magic = 0xCAFEBABE;
        fmt_array[i].priv_offset = 64;
        fmt_array[i].priv_length = 128;
        fmt_array[i].pub_offset = 192;
        fmt_array[i].pub_length = 64;

        fmt_pref_array[i].fmt = &fmt_array[i];
        fmt_pref_array[i].pref = i;
    }

    fmt_slots = fmt_pref_array;
    p8fmt = NULL;
    slot = NULL;
    pos = data_buffer + sizeof(data_buffer);
    len = 32;
    magic = 0x12345678U;

    memset(data_buffer, 0, sizeof(data_buffer));
}