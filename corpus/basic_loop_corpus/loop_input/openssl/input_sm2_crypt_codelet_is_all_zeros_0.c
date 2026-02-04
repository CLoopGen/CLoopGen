#include <inttypes.h>
#include <stdlib.h>

unsigned char *msg;
size_t msglen;
unsigned char re;
size_t i;

void init_vars() {
    msglen = 512 * 1024; // 512 KB data size for ~0.01 sec runtime
    msg = (unsigned char *)malloc(msglen);
    if (!msg) {
        msglen = 0;
        return;
    }
    for (size_t j = 0; j < msglen; j++) {
        msg[j] = (unsigned char)(j & 0xFF);
    }
    re = 0;
    i = 0;
}