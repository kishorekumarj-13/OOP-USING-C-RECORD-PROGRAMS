
#include <iostream>
#include <cassert>
using namespace std;

class Matrix
{
private:
    int data[2][2];

public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    // Operator +
    Matrix operator+(const Matrix &m)
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = data[i][j] + m.data[i][j];
            }
        }

        return result;
    }

    // Operator *
    Matrix operator*(const Matrix &m)
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = 0;

                for (int k = 0; k < 2; k++)
                {
                    result.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }

        return result;
    }

    // Operator []
    int* operator[](int index)
    {
        return data[index];
    }

    // Operator <<
    friend ostream& operator<<(ostream &out, const Matrix &m)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                out << m.data[i][j] << " ";
            }
            out << endl;
        }

        return out;
    }
};

int main()
{
    Matrix A(11, 12, 13, 14);
    Matrix B(15, 16, 17, 18);

    Matrix sum = A + B;
    Matrix product = A * B;

    // Addition unit tests
    assert(sum[0][0] == 26);
    assert(sum[0][1] == 28);
    assert(sum[1][0] == 30);
    assert(sum[1][1] == 32);

    // Multiplication unit tests
    assert(product[0][0] == 369);
    assert(product[0][1] == 392);
    assert(product[1][0] == 433);
    assert(product[1][1] == 460);

    cout << "Matrix A:" << endl;
    cout << A;

    cout << "Matrix B:" << endl;
    cout << B;

    cout << "Addition of Matrices:" << endl;
    cout << sum;

    cout << "Multiplication of Matrices:" << endl;
    cout << product;

    cout << "All unit tests passed successfully." << endl;

    return 0;
}
