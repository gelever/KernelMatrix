#include "km_utilities.hpp"

using namespace KernelMatrix;

int main(int argc, char* argv[])
{
    DenseMatrix test_mat(3, 3);
    test_mat(0, 0) = 1.0;
    test_mat(1, 1) = 2.0;
    test_mat(2, 2) = 3.0;

    int width = 8;
    int precision = 0;
    test_mat.Print("Test Matrix:", std::cout, width, precision);

    int test_func = some_function(test_mat);

    std::cout << "This is a test example file: " << test_func << "\n";
}
