#include <stdint.h>
#include <string.h>

typedef struct ssl_st SSL;

union {
    int fd;
    void *custom;
    uintptr_t custom_ui;
    SSL *ssl;
};

typedef struct bio_poll_descriptor_st {
    uint32_t type;
    union {
        int fd;
        void *custom;
        uintptr_t custom_ui;
        SSL *ssl;
    } value;
} BIO_POLL_DESCRIPTOR;

typedef struct ssl_poll_item_st {
    BIO_POLL_DESCRIPTOR desc;
    uint64_t events;
    uint64_t revents;
} SSL_POLL_ITEM;

SSL_POLL_ITEM items[6];
SSL_POLL_ITEM expected_items[6];
size_t i;

void init_vars() {
    memset(items, 0, sizeof(items));
    memset(expected_items, 0, sizeof(expected_items));
    
    for (int j = 0; j < 6; ++j) {
        items[j].desc.type = j;
        items[j].events = 0;
        items[j].revents = 0;
        
        expected_items[j].desc.type = j;
        expected_items[j].events = 0;
        expected_items[j].revents = 0;
    }
}