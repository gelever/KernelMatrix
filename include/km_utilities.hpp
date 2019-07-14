#ifndef KM_UTILITIES_HPP
#define KM_UTILITIES_HPP

#include "linalgcpp.hpp"

namespace KernelMatrix
{

// Aliases to avoid unnecessary type verbosity
using SparseMatrix = linalgcpp::SparseMatrix<double>;
using DenseMatrix = linalgcpp::DenseMatrix;
using CooMatrix = linalgcpp::CooMatrix<double>;
using Vector = linalgcpp::Vector<double>;
using VectorView = linalgcpp::VectorView<double>;
using Timer = linalgcpp::Timer;
using Operator = linalgcpp::Operator;

using linalgcpp::linalgcpp_verify;
using linalgcpp::linalgcpp_assert;
// End Aliases

} // namespace KernelMatrix

#endif // KM_UTILITIES_HPP
