#include <iostream>
#include <vector>
#include <cmath>

/**
 * @brief Генерирует коэффициенты многочленов Чебышёва до степени n-1.
 * @param coeffs Вектор для хранения коэффициентов многочленов Чебышёва.
 * @param n Количество многочленов Чебышёва для генерации.
 */
void generateChebyshevCoefficients(std::vector<std::vector<double>>& coeffs, const int n)
{
    for (size_t i = 2; i < n; ++i)
    {
        std::vector<double> t_i(i + 1, 0);

        for (size_t j = 0; j < coeffs[i - 1].size(); ++j)
        {
            t_i[j + 1] += 2 * coeffs[i - 1][j];
        }
        for (size_t j = 0; j < coeffs[i - 2].size(); ++j)
        {
            t_i[j] -= coeffs[i - 2][j];
        }
        coeffs.push_back(t_i);
    }
}

/**
 * @brief Вычисляет значение многочлена Чебышёва в точке x с использованием схемы Горнера.
 * @param coeffs Коэффициенты многочлена Чебышёва.
 * @param x Точка, в которой вычисляется значение многочлена.
 * @return Значение многочлена в точке x.
 */
double evaluateHorner(const std::vector<double>& coeffs, double x)
{
    double result = 0.0;
    for (int i = coeffs.size() - 1; i >= 0; --i)
    {
        result = result * x + coeffs[i];
    }
    return result;
}

/**
 * @brief Вычисляет значение многочлена Чебышёва в точке x с использованием тригонометрической формулы.
 * @param n Степень многочлена Чебышёва.
 * @param x Точка, в которой вычисляется значение многочлена.
 * @return Значение многочлена в точке x.
 */
double evaluateTrigonometric(const size_t n, double x)
{
    if (x < -1.0 || x > 1.0)
    {
        throw std::out_of_range("x must be in the range [-1, 1] for the trigonometric formula.");
    }
    return cos(n * acos(x));
}

/**
 * @brief Считывает положительное целое число из стандартного ввода.
 * @param message Сообщение для вывода перед вводом.
 * @return Считанное положительное целое число.
 * @throws std::invalid_argument если ввод некорректен или не является положительным числом.
 */
size_t positiveInput(const char* message)
{
    std::cout << message;
    int value;
    if (!(std::cin >> value) || value <= 0)
    {
        throw std::invalid_argument("Input must be a positive integer.");
    }
    return static_cast<size_t>(value);
}

/**
 * @brief Точка входа в программу.
 * @return возвращет 0 в случае успеха, иначе 1.
 */
int main(void)
{
    const size_t n = positiveInput("Enter n (Number of Chebyshev polynomials to generate): ");
    std::vector<std::vector<double>> chebyshevCoeffs;
    
    for (int i = -10; i <= 10; ++i)
    {
        double x_normalized = i / 10.0;

        chebyshevCoeffs.push_back({1});
        chebyshevCoeffs.push_back({0, 1});

        generateChebyshevCoefficients(chebyshevCoeffs, n);

        std::cout << "x: " << x_normalized << "\n";
        for (size_t i = 0; i < n; ++i)
        {
            double hornerValue = evaluateHorner(chebyshevCoeffs[i], x_normalized);
            double trigValue = evaluateTrigonometric(i, x_normalized);
            std::cout << "T_" << i << "(x) Horner: " << hornerValue
                      << ", Trigonometric: " << trigValue << "\n";
        }
        std::cout << "-----------------------------------\n";
    }

    return 0;
}