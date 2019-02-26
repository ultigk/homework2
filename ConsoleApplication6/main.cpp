#include <iostream>
#include <vector>
#include "profile.h"
#include "matrix.h"

#define ASSERT_EQUAL(x, y)                                         \
    if ((x) != (y))                                                \
    {                                                              \
        std::cerr << "Assertion failed. File: " << __FILE__        \
            << " Line: " << __LINE__ << " "                        \
            << x << " != " << y << " ("                            \
            << #x << " != " << #y << ")" << std::endl;             \
        fails_count++;                                             \
    }


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


void TestMatrix()
{
    std::cerr << "----------------------" << std::endl;
    int fails_count = 0;
    Matrix testmatrix(2, 2);

    ASSERT_EQUAL(testmatrix.GetValue(0, 0), 0);
    ASSERT_EQUAL(testmatrix.GetValue(0, 1), 0);
    ASSERT_EQUAL(testmatrix.GetValue(1, 0), 0);
    ASSERT_EQUAL(testmatrix.GetValue(1, 0), 0);

    if (fails_count == 0)
    {
        std::cerr << "TestMatrix: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestMatrix fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------" << std::endl;
}

void TestGetHeight()
{
    std::cerr << "----------------------" << std::endl;
    int fails_count = 0;

    Matrix testmatrix(3, 3);
    ASSERT_EQUAL(testmatrix.GetHeight(), 3);

    if (fails_count == 0)
    {
        std::cerr << "TestGetHeight: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestGetHeight fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------" << std::endl;
}

void TestGetWidth()
{
    std::cerr << "----------------------" << std::endl;
    int fails_count = 0;

    Matrix testmatrix(5, 5);
    ASSERT_EQUAL(testmatrix.GetWidth(), 5);

    if (fails_count == 0)
    {
        std::cerr << "TestGetWidth: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestGetWidth fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------" << std::endl;
}

void TestGetValue()
{
    std::cerr << "----------------------" << std::endl;
    int fails_count = 0;

    Matrix testmatrix(10, 10);
    ASSERT_EQUAL(testmatrix.GetValue(0, 0), 0);

    if (fails_count == 0)
    {
        std::cerr << "TestGetValue: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestGetValue fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------" << std::endl;
}

void TestSetValue()
{
    std::cerr << "----------------------" << std::endl;
    int fails_count = 0;

    Matrix testmatrix(8, 8);
    testmatrix.SetValue(5, 7, 10);
    ASSERT_EQUAL(testmatrix.GetValue(5, 7), 10);

    if (fails_count == 0)
    {
        std::cerr << "TestSetValue: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestSetValue fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------" << std::endl;
}

void TestTranspose()
{
    std::cerr << "----------------------" << std::endl;
    int fails_count = 0;

    Matrix testmatrix(3, 3);
    testmatrix.SetValue(0, 0, 1);
    testmatrix.SetValue(0, 1, 2);
    testmatrix.SetValue(0, 2, 3);
    testmatrix.SetValue(1, 0, 4);
    testmatrix.SetValue(1, 1, 5);
    testmatrix.SetValue(1, 2, 6);
    testmatrix.SetValue(2, 0, 7);
    testmatrix.SetValue(2, 1, 8);
    testmatrix.SetValue(2, 2, 9);
    testmatrix = testmatrix.Transpose();
    ASSERT_EQUAL(testmatrix.GetValue(0, 1), 4);
    ASSERT_EQUAL(testmatrix.GetValue(1, 2), 8);
    ASSERT_EQUAL(testmatrix.GetValue(2, 0), 3);

    if (fails_count == 0)
    {
        std::cerr << "TestTranspose: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestTranspose fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------" << std::endl;
}

void TestMultiply()
{
    std::cerr << "----------------------" << std::endl;
    int fails_count = 0;

    Matrix testmatrix1(2, 2);
    testmatrix1.SetValue(0, 0, 1);
    testmatrix1.SetValue(0, 1, 2);
    testmatrix1.SetValue(1, 0, 3);
    testmatrix1.SetValue(1, 1, 4);

    Matrix testmatrix2(2, 2);
    testmatrix2.SetValue(0, 0, 5);
    testmatrix2.SetValue(0, 1, 6);
    testmatrix2.SetValue(1, 0, 7);
    testmatrix2.SetValue(1, 1, 8);

    Matrix testres = testmatrix1 * testmatrix2;
    ASSERT_EQUAL(testres.GetValue(0, 0), 19);
    ASSERT_EQUAL(testres.GetValue(0, 1), 22);
    ASSERT_EQUAL(testres.GetValue(1, 0), 43);
    ASSERT_EQUAL(testres.GetValue(1, 1), 50);

    if (fails_count == 0)
    {
        std::cerr << "TestOperator*: OK" << std::endl;
    }
    else
    {
        std::cerr << "TestOperator* fails. fails_count = " << fails_count << std::endl;
    }
    std::cerr << "----------------------" << std::endl;
}


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

    TestMatrix();
    TestGetHeight();
    TestGetWidth();
    TestGetValue();
    TestSetValue();
    TestTranspose();
    TestMultiply();

    return 0;
}


