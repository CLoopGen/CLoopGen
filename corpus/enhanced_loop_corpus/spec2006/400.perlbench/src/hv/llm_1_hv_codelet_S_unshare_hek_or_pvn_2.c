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



void loop(){
    // Flattened version: reduce effective nesting by eliminating inner control flow
    // This variant avoids any potential inner loops or conditionals that branch deeply

    I32 temp_i = 0;
    HE **ptr = oentry;

    for (entry = *ptr; entry; temp_i = 0, ptr = &(entry)->hent_next, entry = *ptr) {
        found = ((entry)->hent_hek == hek);
        if (found)
            break;
    }

    i = temp_i; // preserve side effect on original variable
}
