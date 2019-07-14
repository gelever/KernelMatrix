#ifndef KM_UTILITIES_HPP
#define KM_UTILITIES_HPP

#include "linalgcpp.hpp"

namespace KernelMatrixProject
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

using ArgParser = linalgcpp::ArgParser;
// End Aliases

DenseMatrix UnitSquareCoordinates(int refinements = 0);

} // namespace KernelMatrixProject

#endif // KM_UTILITIES_HPP
