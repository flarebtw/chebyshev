#include <iostream>
#include <cmath>

/**
 * @brief Вычисляет значение многочлена Чебышёва T_n(x) рекурсивно
 * @param n Порядок многочлена Чебышёва
 * @param x Точка, в которой вычисляется значение многочлена
 * @return Значение многочлена Чебышёва T_n(x)
 */
double getChebyshev(const int n, const double x)
{
    double t0 = 1.0;
    double t1 = x;
    double t2 = 0.0;
    for (int i = 2; i <= n; i++)
    {
        t2 = 2 * x * t1 - t0;
        t0 = t1;
        t1 = t2;
    }
    return t1;
}

int positiveInput(const char* message)
{
    std::cout << message << std::endl;
    int value = 0;
    if (!(std::cin >> value) || value < 0)
    {
        std::cerr << "Input error. Please enter a positive integer value." << std::endl;
        exit(1);
    }
    return value;
}

/**
 * @brief Считывает целое число из стандартного ввода
 * @return Считанное целое число
 */
int input(void)
{
    int value = 0;
    if (!(std::cin >> value))
    {
        std::cerr << "Input error. Please enter an integer value." << std::endl;
        exit(1);
    }
    return value;
}
/**
 * @brief Точка входа в программу
 * @return 0 в случае успеха, иначе 1
 */
int main(void)
{
    int n, begin, end = 0;
    
    n = positiveInput("Enter degree of Chebyshev polynomial: ");

    std::cout << "Enter begin of interval: " << std::endl;
    begin = input();

    std::cout << "Enter end of interval: " << std::endl;
    end = input();

    if (begin >= end)
    {
        std::cerr << "Input error. Begin of interval must be less than end." << std::endl;
        exit(1);
    }
    
    for (int i = begin * 10; i <= end * 10; i++)
    {
        double x = i / 10.0;
        std::cout << "T[" << n << "](" << x << ") = " << getChebyshev(n, x) << std::endl;
    }

    std::cout << "--------------------------------------" << std::endl;

    std::cout << "Evaluation with trigonometric formula:" << std::endl;
    for (int i = begin * 10; i <= end * 10; i++)
    {
        double x = i / 10.0;
        if (x < -1.0 || x > 1.0)
        {
            std::cout << "T[" << n << "](" << x << ") is out of range for trigonometric formula." << std::endl;
            exit(1);
        }
        else
        {
            std::cout << "T[" << n << "](" << x << ") = " << std::cos(n * std::acos(x)) << std::endl;
        }
    }

    return 0;
}