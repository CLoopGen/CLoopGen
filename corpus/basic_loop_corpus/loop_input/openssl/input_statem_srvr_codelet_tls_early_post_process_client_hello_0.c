#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

CLIENTHELLO_MSG *clienthello;
int comp_id;
unsigned int k;

static unsigned char static_compressions[255];
static PACKET static_ciphersuites;
static PACKET static_extensions;
static RAW_EXTENSION *static_pre_proc_exts;
static RAW_EXTENSION static_raw_extensions_buffer[10];  // dummy size
static unsigned char static_curr_data[1024];

void init_vars() {
    clienthello = (CLIENTHELLO_MSG*)malloc(sizeof(CLIENTHELLO_MSG));
    
    clienthello->isv2 = 0;
    clienthello->legacy_version = 0x0303;
    memset(clienthello->random, 0x11, 32);
    clienthello->session_id_len = 32;
    memset(clienthello->session_id, 0x22, 32);
    clienthello->dtls_cookie_len = 0;
    memset(clienthello->dtls_cookie, 0x33, 255);
    
    static_ciphersuites.curr = static_curr_data;
    static_ciphersuites.remaining = 32;
    clienthello->ciphersuites = static_ciphersuites;
    
    clienthello->compressions_len = 255;
    memset(static_compressions, 0xFF, 255);
    comp_id = 0x42;
    static_compressions[254] = comp_id;
    memcpy(clienthello->compressions, static_compressions, 255);
    
    static_extensions.curr = static_curr_data + 512;
    static_extensions.remaining = 256;
    clienthello->extensions = static_extensions;
    
    clienthello->pre_proc_exts_len = 10;
    static_pre_proc_exts = static_raw_extensions_buffer;
    clienthello->pre_proc_exts = static_pre_proc_exts;
    
    for (size_t i = 0; i < clienthello->pre_proc_exts_len; i++) {
        static_pre_proc_exts[i].present = 1;
        static_pre_proc_exts[i].parsed = 0;
        static_pre_proc_exts[i].type = i;
        static_pre_proc_exts[i].received_order = i;
        static_pre_proc_exts[i].data.curr = static_curr_data + i * 8;
        static_pre_proc_exts[i].data.remaining = 8;
    }
    
    k = 0;
}