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

// External variables
DLTensor *dl_tensor;
npy_intp itemsize;
int ndim;
npy_intp *strides;
npy_intp *shape;

// Internal storage arrays
static int64_t internal_shape[16];
static int64_t internal_strides[16];
static npy_intp sim_strides[16];
static npy_intp sim_shape[16];

static DLTensor sim_dl_tensor;

void init_vars() {
    // Aim for ~64MB of data to ensure loop runs ~0.01s due to memory effects
    ndim = 4;
    itemsize = 8; // double

    sim_shape[0] = 50;
    sim_shape[1] = 50;
    sim_shape[2] = 50;
    sim_shape[3] = 50;

    sim_strides[0] = sim_shape[1] * sim_shape[2] * sim_shape[3] * itemsize;
    sim_strides[1] = sim_shape[2] * sim_shape[3] * itemsize;
    sim_strides[2] = sim_shape[3] * itemsize;
    sim_strides[3] = itemsize;

    for (int i = 0; i < ndim; ++i) {
        internal_shape[i] = sim_shape[i];
        internal_strides[i] = sim_strides[i];
    }

    shape = sim_shape;
    strides = sim_strides;

    sim_dl_tensor.data = malloc(50 * 50 * 50 * 50 * itemsize);
    sim_dl_tensor.device.device_type = kDLCPU;
    sim_dl_tensor.device.device_id = 0;
    sim_dl_tensor.ndim = ndim;
    sim_dl_tensor.dtype.code = 2;  // float
    sim_dl_tensor.dtype.bits = 64;
    sim_dl_tensor.dtype.lanes = 1;
    sim_dl_tensor.shape = internal_shape;
    sim_dl_tensor.strides = internal_strides;
    sim_dl_tensor.byte_offset = 0;

    dl_tensor = &sim_dl_tensor;
}