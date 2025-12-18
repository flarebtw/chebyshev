#include <iostream>
#include <cmath>
#include <string>

/**
 * @brief Точка входа в программу
 * @return 0 в случае успеха, иначе 1
 */
int main(void)
{
    const int n = 7;
    std::cout << "Zeros of Chebyshev polynomial of degree " << n << std::endl;
    for (int k = 0; k < n; k++)
    {
        double zero = std::cos(M_PI * (2 * k + 1) / (2 * n));
        std::cout << "Zero " << k + 1 << ": " << zero << std::endl;
    }

    std::cout << "-------------------------------------------" << std::endl;

    std::cout << "Extrema of Chebyshev polynomial of degree " << n << std::endl;
    for (int k = 0; k <= n; k++)
    {
        double extremum = std::cos(M_PI * k / n);
        std::string maxOrMin = (k % 2 == 0) ? "max" : "min";
        std::cout << "Extremum " << k + 1 << ": x = " << extremum << ", " << maxOrMin << std::endl;
    }

    return 0;
}