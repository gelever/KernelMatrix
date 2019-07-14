#include "KernelMatrixProject.hpp"

using namespace KernelMatrixProject;

void test_kernel_matrix(const std::string& label,
                        const KernelMatrix& kernel_mat,
                        VectorView rhs);

double calc_memory_reqs_gb(const KernelMatrix& kernel_mat);

int main(int argc, char* argv[])
{
    // Parameters
    double shift = 0.0;
    int num_refinements = 1;

    ArgParser arg_parser(argc, argv);
    arg_parser.Parse(shift, "--shift", "Kernel Matrix Shift Parameter");
    arg_parser.Parse(num_refinements, "--nr", "Number of Unit Square Refinements");

    if (!arg_parser.IsGood())
    {
        arg_parser.ShowHelp();
        arg_parser.ShowErrors();

        return EXIT_FAILURE;
    }

    arg_parser.ShowOptions();

    // Create uniform square mesh on unit square
    DenseMatrix data = UnitSquareCoordinates(num_refinements);

    // Define some kernel matrices
    KernelMatrix kernel_mat_gauss(data, gauss_kernel, shift);
    KernelMatrix kernel_mat_poly(data, poly_kernel<2, 0>, shift);
    KernelMatrix kernel_mat_distance(data, distance_kernel, shift);

    // Create random right hand side
    Vector x(data.Cols());
    x.Randomize(0.0, 1.0);
    x.Normalize();

    // Apply kernel matrix
    test_kernel_matrix("Gauss Kernel", kernel_mat_gauss, x);
    test_kernel_matrix("Polynomial Kernel", kernel_mat_poly, x);
    test_kernel_matrix("Distance Kernel", kernel_mat_distance, x);
}

void test_kernel_matrix(const std::string& label, const KernelMatrix& kernel_mat,
                        VectorView rhs)
{
    Timer timer(Timer::Start::True);
    kernel_mat.Mult(rhs);
    timer.Click();

    std::cout << "------------------------------------\n";
    std::cout << "Kernel Type         " << label << "\n";
    std::cout << "Matrix Size         " << kernel_mat.Rows() << "\n";
    std::cout << "Memory to Assemble  " << calc_memory_reqs_gb(kernel_mat) << " GB\n";
    std::cout << "Mult Time           " << timer.TotalTime() << " seconds\n";
}

double calc_memory_reqs_gb(const KernelMatrix& kernel_mat)
{
    int n = kernel_mat.Rows();
    int m = kernel_mat.Cols();
    double gb = 1024 * 1024 * 1024;

    return (sizeof(double) * n * m) / gb;
}
