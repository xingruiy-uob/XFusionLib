#ifndef FUSION_ICP_ESTIMATION_H
#define FUSION_ICP_ESTIMATION_H

#include <sophus/se3.hpp>
#include <opencv2/cudaarithm.hpp>
#include <xfusion/core/intrinsic_matrix.h>

namespace fusion
{

// Simple Dense Image Alignment
// NOTE: easily affected by outliers
void rgb_reduce(
    const cv::cuda::GpuMat &curr_intensity,
    const cv::cuda::GpuMat &last_intensity,
    const cv::cuda::GpuMat &last_vmap,
    const cv::cuda::GpuMat &curr_vmap,
    const cv::cuda::GpuMat &intensity_dx,
    const cv::cuda::GpuMat &intensity_dy,
    cv::cuda::GpuMat &sum,
    cv::cuda::GpuMat &out,
    const Sophus::SE3d &pose,
    const IntrinsicMatrix K,
    float *jtj, float *jtr,
    float *residual);

// Point-to-Plane ICP
// This computes one icp step and returns hessian
void icp_reduce(
    const cv::cuda::GpuMat &curr_vmap,
    const cv::cuda::GpuMat &curr_nmap,
    const cv::cuda::GpuMat &last_vmap,
    const cv::cuda::GpuMat &last_nmap,
    cv::cuda::GpuMat &sum,
    cv::cuda::GpuMat &out,
    const Sophus::SE3d &pose,
    const IntrinsicMatrix K,
    float *jtj, float *jtr,
    float *residual);

} // namespace fusion

#endif