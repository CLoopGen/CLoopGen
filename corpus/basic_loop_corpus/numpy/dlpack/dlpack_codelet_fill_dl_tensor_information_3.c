#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef enum {
    kDLCPU = 1,
    kDLCUDA = 2,
    kDLCUDAHost = 3,
    kDLOpenCL = 4,
    kDLVulkan = 7,
    kDLMetal = 8,
    kDLVPI = 9,
    kDLROCM = 10,
    kDLROCMHost = 11,
    kDLExtDev = 12,
    kDLCUDAManaged = 13,
    kDLOneAPI = 14,
    kDLWebGPU = 15,
    kDLHexagon = 16,
    kDLMAIA = 17
} DLDeviceType;

typedef struct {
    DLDeviceType device_type;
    int32_t device_id;
} DLDevice;

typedef struct {
    uint8_t code;
    uint8_t bits;
    uint16_t lanes;
} DLDataType;

typedef struct {
    void *data;
    DLDevice device;
    int32_t ndim;
    DLDataType dtype;
    int64_t *shape;
    int64_t *strides;
    uint64_t byte_offset;
} DLTensor;

typedef ssize_t Py_ssize_t;

typedef Py_ssize_t npy_intp;

extern DLTensor *dl_tensor;
extern npy_intp itemsize;
extern int ndim;
extern npy_intp *strides;
extern npy_intp *shape;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 0; i < ndim; ++i) {
    dl_tensor->shape[i] = shape[i];
    dl_tensor->strides[i] = strides[i] / itemsize;
}

}
