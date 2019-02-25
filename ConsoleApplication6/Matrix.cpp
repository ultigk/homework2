#include "matrix.h"
#include "profile.h"

#define ASSERT_EQUAL(x, y)                                         \
    if ((x) != (y))                                                \
    {                                                              \
        std::cerr << "Assertion failed. File: " << __FILE__        \
            << " Line: " << __LINE__ << " "                        \
            << x << " != " << y << " ("                            \
            << #x << " != " << #y << ")" << std::endl;             \
        fails_count++;                                             \
    }

std::istream& operator >> (std::istream& input_stream, Matrix& matrix)
{
    for (size_t y = 0; y < matrix.GetHeight(); y++)
    {
        for (size_t x = 0; x < matrix.GetWidth(); x++)
        {
            int temp_int = 0;
            input_stream >> temp_int;
            matrix.SetValue(y, x, temp_int);
        }
    }
    return input_stream;
}

std::ostream& operator << (std::ostream& output_stream, const Matrix& matrix)
{
    for (size_t y = 0; y < matrix.GetHeight(); y++)
    {
        for (size_t x = 0; x < matrix.GetWidth(); x++)
        {
            output_stream << matrix.GetValue(y, x) << " ";
        }
        std::cout << std::endl;
    }
    return output_stream;
}

Matrix::Matrix(const size_t height, const size_t width)
{
    data_.reserve(height);
    for (size_t y = 0; y < height; y++)
    {
        std::vector<int> temp_vec;
        temp_vec.reserve(width);
        for (size_t x = 0; x < width; x++)
        {
            temp_vec.push_back(0);  
        }
        data_.push_back(temp_vec);
    }
}

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

size_t Matrix::GetHeight() const
{
    return data_.size();
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

size_t Matrix::GetWidth() const
{
    if (data_.size())
    {
        return data_[0].size();
    }
    return 0;
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

int Matrix::GetValue(const size_t height_index, const size_t width_index) const
{
    return data_[height_index][width_index];
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

void Matrix::SetValue(const size_t height_index, const size_t width_index,
    const int value)
{
    data_[height_index][width_index] = value;
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


Matrix Matrix::Transpose() const
{
    Matrix res(GetHeight(), GetWidth());
    for (size_t x = 0; x < res.GetWidth(); x++)
    {
        for (size_t y = 0; y < res.GetHeight(); y++)
        {
            res.SetValue(y, x, data_[x][y]);
        }
    }
    return res;
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
    testmatrix.Transpose();
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


Matrix Matrix::operator * (const Matrix& rhs)
{
    if (GetWidth() != rhs.GetHeight())
    {
        std::cout << "Умножение невозможно! " << std::endl;
        Matrix res(0, 0);
        return res;
    }
    Matrix res(GetHeight(), rhs.GetWidth());
    int temp = 0;
    data_.reserve(GetHeight());
    for (size_t y = 0; y < GetHeight(); y++)
    {
        data_.reserve(rhs.GetWidth());
        for (size_t x = 0; x < rhs.GetWidth(); x++)
        {
            data_.reserve(GetWidth());
            for (size_t z = 0; z < GetWidth(); z++)
            {
                temp += data_[y][z] * rhs.GetValue(x, z);
            }
            res.SetValue(y, x, temp);
            temp = 0;
        }
    }
    return res;
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

