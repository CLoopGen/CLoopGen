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
    // Variant 1: Strided memory access with step size of 2, unrolled to process two elements per iteration
    size_t len = clienthello->compressions_len;
    size_t i;
    for (i = 0; i < len; i += 2) {
        if (i < len && clienthello->compressions[i] == comp_id) {
            k = i;
            return;
        }
        if ((i + 1) < len && clienthello->compressions[i + 1] == comp_id) {
            k = i + 1;
            return;
        }
    }
    // In case no match is found, set k to compressions_len (equivalent to original behavior)
    k = clienthello->compressions_len;
}
