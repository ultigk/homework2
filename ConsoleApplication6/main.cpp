#include <iostream>
#include <vector>
#include "profile.h"
#include "matrix.h"


//#define UNIQ_ID_FINAL(line_number) local_var_##line_number
//#define UNIQ_ID_INTERMEDIATE(line_number) UNIQ_ID_FINAL(line_number)
//#define UNIQ_ID UNIQ_ID_INTERMEDIATE(__LINE__)



/*int main()
{
//int UNIQ_ID = 123;
LOG_DURATION("main start");
int n = 0;
std::cin >> n;
std::vector<int> v;
for (int i = 0; i < n; i++)
{
int temp = 0;
std::cin >> temp;
v.push_back(temp);
}
int sum = 0;
for (int i = 0; i < (int)v.size(); i++)
{
sum += v[i];
}
std::cout << "Average temperature = " << sum / v.size() << std::endl;
//std::cout << "Hello! :)" << std::endl;
//system("pause");
return 0;
}*/





int main()
{
    LOG_DURATION("main");
    int matrix_height = 1000;
    int matrix_width = 1000;
    std::cout << "Input matrix_height_1 and matrix_width_1: " << std::endl;
    std::cin >> matrix_height >> matrix_width;
    Matrix matrix1(matrix_height, matrix_width);
    std::cout << "Input matrix1 elements" << std::endl;
    std::cin >> matrix1;

    std::cout << "matrix1 transposed: " << std::endl;
    std::cout << matrix1.Transpose() << std::endl;

    std::cout << "Input matrix_height_2 and matrix_width_2: " << std::endl;
    std::cin >> matrix_height >> matrix_width;
    Matrix matrix2(matrix_height, matrix_width);
    std::cout << "Input matrix2 elements" << std::endl;
    std::cin >> matrix2;

    Matrix res = matrix1 * matrix2;
    std::cout << "Matrix1 * matrix2 = " << std::endl;
    std::cout << res << std::endl;

    void TestMatrix();
    void TestGetHeight();
    void TestGetWidth();
    void TestGetValue();
    void TestSetValue();
    void TestTranspose();
    void TestMultiply();

    return 0;
}

