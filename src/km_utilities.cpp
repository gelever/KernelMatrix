#include "km_utilities.hpp"

namespace KernelMatrixProject
{

DenseMatrix UnitSquareCoordinates(int refinements)
{
    linalgcpp_assert(refinements >= 0, "Invalid number of refinements");

    int dim = 2;
    int size = std::pow(dim, refinements) + 1;
    int num_points = size * size;

    DenseMatrix coordinates(dim, num_points);

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            int index = i * size + j;

            coordinates(0, index) = j / (size - 1.0);
            coordinates(1, index) = i / (size - 1.0);
        }
    }

    return coordinates;
}

} // namespace KernelMatrixProject
