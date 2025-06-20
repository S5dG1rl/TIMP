#include "dichotomymethod.h"
#include <cassert>
#include <iostream>

void run_tests() {
    // Тест 1: x^2 - 4 = 0 на интервале [0, 3], ожидаем ~2
    DichotomyMethod dm1("x*x - 4", 0, 3, 1e-6, 100);
    double root1 = dm1.solve();
    std::cout << "Test 1: x^2 - 4 on [0, 3] -> " << root1 << "\n";
    assert(fabs(root1 - 2.0) < 1e-5);

    // Тест 2: x^2 - 4 = 0 на интервале [-3, 0], ожидаем ~-2
    DichotomyMethod dm2("x*x - 4", -3, 0, 1e-6, 100);
    double root2 = dm2.solve();
    std::cout << "Test 2: x^2 - 4 on [-3, 0] -> " << root2 << "\n";
    assert(fabs(root2 + 2.0) < 1e-5);

    // Тест 3: sin(x) на [3, 4], ожидаем ~π (~3.14159)
    DichotomyMethod dm3("sin(x)", 3, 4, 1e-6, 100);
    double root3 = dm3.solve();
    std::cout << "Test 3: sin(x) on [3, 4] -> " << root3 << "\n";
    assert(fabs(root3 - M_PI) < 1e-5);

    // Тест 4: x^3 - x - 2 на [1, 2], ожидаем приблизительно 1.521
    DichotomyMethod dm4("x*x*x - x - 2", 1, 2, 1e-6, 100);
    double root4 = dm4.solve();
    std::cout << "Test 4: x^3 - x - 2 on [1, 2] -> " << root4 << "\n";
    assert(fabs(root4 - 1.52138) < 1e-5);

    // Тест 5: функция с отрицательной правой частью
    DichotomyMethod dm5("x*x - 2", 0, 2, 1e-6, 100);
    double root5 = dm5.solve();
    std::cout << "Test 5: x^2 - 2 on [0, 2] -> " << root5 << "\n";
    assert(fabs(root5 - sqrt(2)) < 1e-5);

    std::cout << "All tests passed successfully!" << std::endl;
}

int main() {
    try {
        run_tests();
    }
    catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}