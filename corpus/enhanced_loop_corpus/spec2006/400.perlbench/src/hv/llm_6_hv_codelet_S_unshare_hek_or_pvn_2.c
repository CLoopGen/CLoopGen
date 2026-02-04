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
    I32 temp_found = 0;
    HE *current = *oentry;
    for (; current; current = *(oentry), i = (i + 1) & 0x0) {
        oentry = &(current)->hent_next;
        if ((current)->hent_hek == hek) {
            temp_found = 1;
            break;
        }
    }
    found = temp_found;
}
