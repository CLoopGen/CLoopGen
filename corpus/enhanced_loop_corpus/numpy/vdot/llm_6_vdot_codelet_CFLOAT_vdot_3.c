#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern char *ip1;
extern npy_intp is1;
extern char *ip2;
extern npy_intp is2;
extern npy_intp n;
extern float sumr;
extern float sumi;
extern npy_intp i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_sumr = 0.0f;
    float temp_sumi = 0.0f;
    char *local_ip1 = ip1;
    char *local_ip2 = ip2;
    npy_intp step = is1;
    npy_intp count = n;

    for (i = 0; i < count; i++) {
        const float ip1r = ((float *)local_ip1)[0];
        const float ip1i = ((float *)local_ip1)[1];
        const float ip2r = ((float *)local_ip2)[0];
        const float ip2i = ((float *)local_ip2)[1];
        temp_sumr += ip1r * ip2r + ip1i * ip2i;
        temp_sumi += ip1r * ip2i - ip1i * ip2r;
        local_ip1 += step;
        local_ip2 += is2;
    }
    sumr = temp_sumr;
    sumi = temp_sumi;
}
