#include <stdio.h>

#include <inttypes.h>

typedef struct {
    const unsigned char *curr;
    size_t remaining;
} PACKET;

typedef struct raw_extension_st {
    PACKET data;
    int present;
    int parsed;
    unsigned int type;
    size_t received_order;
} RAW_EXTENSION;

typedef struct {
    unsigned int isv2;
    unsigned int legacy_version;
    unsigned char random[32];
    size_t session_id_len;
    unsigned char session_id[32];
    size_t dtls_cookie_len;
    unsigned char dtls_cookie[255];
    PACKET ciphersuites;
    size_t compressions_len;
    unsigned char compressions[255];
    PACKET extensions;
    size_t pre_proc_exts_len;
    RAW_EXTENSION *pre_proc_exts;
} CLIENTHELLO_MSG;

extern CLIENTHELLO_MSG *clienthello;
extern int comp_id;
extern unsigned int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index map (simulated static indexing pattern)
    // Assume a compile-time constant stride or permutation pattern; here we use reverse order access
    size_t len = clienthello->compressions_len;
    size_t rev_index;
    for (rev_index = 0; rev_index < len; rev_index++) {
        size_t idx = len - 1 - rev_index; // Reverse traversal
        if (clienthello->compressions[idx] == comp_id) {
            k = idx;
            return;
        }
    }
    k = clienthello->compressions_len; // Match not found, set to length as sentinel
}
