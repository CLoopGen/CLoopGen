#include <stdio.h>

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


extern HEK *hek;
extern HE *entry;
extern HE **oentry;
extern I32 i;
extern I32 found;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    HE *local_entry = *oentry;
    U32 hash_match = 0;
    for (; local_entry; local_entry = (hash_match) ? NULL : local_entry->hent_next) {
        hash_match = (local_entry->hent_hek && local_entry->hent_hek->hek_hash == hek->hek_hash) ? 1 : 0;
        if (hash_match && local_entry->hent_hek->hek_len == hek->hek_len &&
            !__builtin_memcmp(local_entry->hent_hek->hek_key, hek->hek_key, (U32)local_entry->hent_hek->hek_len)) {
            found = 1;
            break;
        }
        i = i + 1;
    }
}
