#include "kernel_matrix.hpp"

namespace KernelMatrixProject
{

KernelMatrix::KernelMatrix(DenseMatrix X, Kernel K, double shift)
    : Operator(X.Cols()), X_(std::move(X)), K_(std::move(K)), shift_(shift)
{

}

void KernelMatrix::Mult(const VectorView& b, VectorView x) const
{
    int n = Rows();

    x = 0.0;

    for (int i = 0; i < n; ++i)
    {
        double a_ii = Entry(i, i);
        x[i] += a_ii * b[i];

        for (int j = i + 1; j < n; ++j)
        {
            double a_ij = Entry(i, j);

            x[j] += a_ij * b[i];
            x[i] += a_ij * b[j];
        }
    }
}

double KernelMatrix::Entry(int i, int j) const
{
    const auto&& X_i = X_.GetColView(i);
    const auto&& X_j = X_.GetColView(j);

    double k_ij = K_(X_i, X_j);

    if (i == j)
    {
        k_ij += shift_;
    }

    return k_ij;
}

DenseMatrix KernelMatrix::Assemble() const
{
    DenseMatrix output;

    Assemble(output);

    return output;
}

void KernelMatrix::Assemble(DenseMatrix& output) const
{
    int n = Rows();

    output.SetSize(n, n);

    for (int i = 0; i < n; ++i)
    {
        output(i, i) = Entry(i, i);

        for (int j = i + 1; j < n; ++j)
        {
            double a_ij = Entry(i, j);
            output(i, j) = a_ij;
            output(j, i) = a_ij;
        }
    }
}

DenseMatrix KernelMatrix::Assemble(const std::vector<int>& indices) const
{
    DenseMatrix output;

    Assemble(indices, output);

    return output;
}

void KernelMatrix::Assemble(const std::vector<int>& indices, DenseMatrix& output) const
{
    int n = indices.size();

    output.SetSize(n, n);

    for (int i = 0; i < n; ++i)
    {
        output(i, i) = Entry(indices[i], indices[i]);

        for (int j = i + 1; j < n; ++j)
        {
            double a_ij = Entry(indices[i], indices[j]);
            output(i, j) = a_ij;
            output(j, i) = a_ij;
        }
    }
}

} // namespace KernelMatrixProject
