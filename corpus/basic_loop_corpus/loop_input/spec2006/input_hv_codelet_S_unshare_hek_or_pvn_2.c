#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <inttypes.h>

typedef unsigned int U32;
typedef int I32;

struct hek {
    U32 hek_hash;
    I32 hek_len;
    char hek_key[1];
};

typedef struct hek HEK;

typedef struct he HE;

struct sv {
    void *sv_any;
    U32 sv_refcnt;
    U32 sv_flags;
};

typedef struct sv SV;

struct he {
    HE *hent_next;
    HEK *hent_hek;
    SV *hent_val;
};

HEK *hek;
HE *entry;
HE **oentry;
I32 i;
I32 found;

static HE *he_array = NULL;
static HEK *hek_target = NULL;
static const size_t data_size = 1 << 20; // ~1M entries, adjust for ~0.01 sec runtime

void init_vars() {
    he_array = calloc(data_size, sizeof(HE));
    if (!he_array) exit(1);

    hek_target = malloc(sizeof(HEK) + 15);
    if (!hek_target) exit(1);
    hek_target->hek_hash = 0xDEADBEEF;
    hek_target->hek_len = 8;
    strcpy(hek_target->hek_key, "target_key");

    for (size_t idx = 0; idx < data_size; ++idx) {
        he_array[idx].hent_next = (idx == data_size - 1) ? NULL : &he_array[idx + 1];
        he_array[idx].hent_val = NULL;
        he_array[idx].hent_hek = (idx == data_size / 2) ? hek_target : malloc(sizeof(HEK) + 7);
        if (he_array[idx].hent_hek != hek_target) {
            he_array[idx].hent_hek->hek_hash = 0xCAFEBABE;
            he_array[idx].hent_hek->hek_len = 7;
            strcpy(he_array[idx].hent_hek->hek_key, "dummyxx");
        }
    }

    hek = hek_target;
    oentry = &he_array[0].hent_next;
    entry = *oentry;
    i = 0;
    found = 0;
}