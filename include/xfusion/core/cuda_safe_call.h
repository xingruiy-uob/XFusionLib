#ifndef FUSION_CUDA_SAFE_CALL_H
#define FUSION_CUDA_SAFE_CALL_H

#include <iostream>
#include <cuda_runtime_api.h>

#if defined(__GNUC__)
#define safe_call(expr) ___SafeCall(expr, __FILE__, __LINE__, __func__)
#else
#define safe_call(expr) ___SafeCall(expr, __FILE__, __LINE__)
#endif

static inline void error(const char *error_string, const char *file, const int line, const char *func)
{
    std::cout << "Error: " << error_string << "\t" << file << ":" << line << std::endl;
    exit(0);
}

static inline void ___SafeCall(cudaError_t err, const char *file, const int line, const char *func = "")
{
    if (cudaSuccess != err)
        error(cudaGetErrorString(err), file, line, func);
}

#endif