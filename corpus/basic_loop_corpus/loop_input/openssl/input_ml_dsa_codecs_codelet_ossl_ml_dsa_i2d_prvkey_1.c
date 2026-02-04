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

ML_COMMON_PKCS8_FMT_PREF *fmt_slots;
ML_COMMON_PKCS8_FMT_PREF *slot;
ML_COMMON_PKCS8_FMT *p8fmt;
uint8_t *seed;

static ML_COMMON_PKCS8_FMT fmt_array[512];
static ML_COMMON_PKCS8_FMT_PREF slot_array[512];

void init_vars() {
    fmt_slots = slot_array;
    slot = fmt_slots;
    p8fmt = NULL;
    seed = calloc(768 * 1024, sizeof(uint8_t));
    if (!seed) exit(1);

    for (int i = 0; i < 512; ++i) {
        static char name_buf[16];
        snprintf(name_buf, sizeof(name_buf), "fmt_%d", i);
        
        fmt_array[i].p8_name = strdup(name_buf);
        fmt_array[i].p8_bytes = 1024;
        fmt_array[i].p8_shift = i % 32;
        fmt_array[i].p8_magic = 0x12345678U + i;
        fmt_array[i].seed_magic = 0xABCDU + (i & 0xFFFF);
        fmt_array[i].seed_offset = 64;
        fmt_array[i].seed_length = (i == 256) ? 0 : 32;
        fmt_array[i].priv_magic = 0xCAFEBABE;
        fmt_array[i].priv_offset = 128;
        fmt_array[i].priv_length = 256;
        fmt_array[i].pub_offset = 384;
        fmt_array[i].pub_length = 128;

        slot_array[i].fmt = &fmt_array[i];
        slot_array[i].pref = i;
    }

    slot_array[511].fmt = NULL;
}