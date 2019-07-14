#ifndef KM_KERNEL_HPP
#define KM_KERNEL_HPP

#include "km_utilities.hpp"

namespace KernelMatrixProject
{

using Kernel = std::function<double(const VectorView& x_i, const VectorView& x_j)>;

template <int Degree = 2, int Theta = 0>
auto poly_kernel = [](const VectorView& x_i, const VectorView& x_j)
{
    double dot_product = x_i.Mult(x_j);

    return std::pow(dot_product, Degree) + Theta;
};

auto gauss_kernel = [](const VectorView& x_i, const VectorView& x_j)
{
    linalgcpp_assert(x_i.size() == x_j.size(), "Kernel vector mismatch!");

    double diff = 0.0;
    int n = x_i.size();

    for (int i = 0; i < n; ++i)
    {
        double diff_i = x_i[i] - x_j[i];
        diff += diff_i * diff_i;
    }

    return std::exp(-0.5 * diff);
};

auto distance_kernel = [](const VectorView& x_i, const VectorView& x_j)
{
    linalgcpp_assert(x_i.size() == x_j.size(), "Kernel vector mismatch!");

    double diff_squared = 0.0;
    int n = x_i.size();

    for (int i = 0; i < n; ++i)
    {
        double diff_i = x_i[i] - x_j[i];
        diff_squared += diff_i * diff_i;
    }

    return std::sqrt(diff_squared);
};


} // namespace KernelMatrixProject

#endif // KM_KERNEL_HPP

