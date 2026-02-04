#include <inttypes.h>
#include <string.h>

int i = 0;
char implicitly_dies[53];

void init_vars() {
    memset(implicitly_dies, 0, sizeof(implicitly_dies));
    implicitly_dies[15] = 1;
}