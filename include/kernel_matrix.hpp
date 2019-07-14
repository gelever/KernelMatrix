#ifndef KM_KERNEL_MATRIX_HPP
#define KM_KERNEL_MATRIX_HPP

#include "kernel.hpp"

namespace KernelMatrixProject
{

class KernelMatrix : public Operator
{
    public:
        KernelMatrix() = default;
        KernelMatrix(DenseMatrix X, Kernel K, double shift);

        using Operator::Mult;
        void Mult(const VectorView& b, VectorView x) const;

        double Entry(int i, int j) const;

        void Assemble(DenseMatrix& output) const;
        DenseMatrix Assemble() const;

        void Assemble(const std::vector<int>& indices, DenseMatrix& output) const;
        DenseMatrix Assemble(const std::vector<int>& indices) const;

    private:
        DenseMatrix X_;
        Kernel K_;

        double shift_;
};

} // namespace KernelMatrix

#endif // KM_KERNEL_MATRIX_HPP
