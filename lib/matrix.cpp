#include "matrix.hpp"
#include "exception.hpp"

Matrix::Matrix(){};

Matrix::Matrix(size_t rows, size_t cols)
    : mRows(rows), mCols(cols), mValues(new double[this->size()]){};

Matrix::Matrix(size_t rows, size_t cols, const double *values)
    : mRows(rows), mCols(cols), mValues(new double[this->size()])
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            mValues[i * cols + j] = values[i * cols + j];
};

Matrix::~Matrix()
{
    delete[] mValues;
};

size_t Matrix::size() const
{
    return this->mRows * this->mCols;
}

size_t Matrix::numRows() const
{
    return this->mRows;
}

size_t Matrix::numCols() const
{
    return this->mCols;
}

Matrix Matrix::like(const Matrix &mat)
{
    return Matrix(mat.mRows, mat.mCols);
}

Matrix Matrix::copy(const Matrix &mat)
{
    return Matrix(mat.mRows, mat.mCols, mat.mValues);
}

Matrix operator+(const Matrix &mat)
{
    return Matrix::copy(mat);
}

Matrix operator-(const Matrix &mat)
{
    Matrix mRes = Matrix::copy(mat);
    for (size_t i = 0; i < mat.size(); i++)
        mRes.mValues[i] = -mat.mValues[i];
    return mRes;
}

Matrix operator+(const Matrix &fst, const Matrix &snd)
{
    if (fst.mRows != snd.mRows || fst.mCols != snd.mCols)
    {
        throw IndexMismatch;
    }

    Matrix mRes = Matrix::like(fst);
    for (size_t i = 0; i < fst.size(); i++)
        mRes.mValues[i] = fst.mValues[i] + snd.mValues[i];
    return mRes;
}

Matrix operator-(const Matrix &fst, const Matrix &snd)
{
    return fst + (-snd);
}

Matrix operator*(const Matrix &fst, const Matrix &snd)
{
    if (fst.mCols != snd.mRows)
    {
        throw IndexMismatch;
    }
    Matrix mRes = Matrix(fst.mRows, snd.mCols);

    for (size_t i = 0; i < fst.mRows; i++)
        for (size_t j = 0; j < fst.mRows; j++)
        {
            mRes.mValues[i * mRes.mCols + j] = 0;
            for (size_t k = 0; k < fst.mCols; k++)
                mRes.mValues[i * mRes.mCols + j] +=
                    fst.mValues[i * fst.mCols + k] * snd.mValues[k * snd.mCols + j];
        }
    return mRes;
}

Matrix operator*(const double mult, const Matrix &snd)
{
    Matrix mRes = Matrix::copy(snd);
    for (size_t i = 0; i < snd.size(); i++)
        mRes.mValues[i] *= mult;
    return mRes;
}

Matrix operator*(const Matrix &fst, const double mult)
{
    return mult * fst;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
{
    os << "Matrix ["
       << matrix.mRows
       << ", "
       << matrix.mCols
       << "]"
       << std::endl;

    for (size_t i = 0; i < matrix.mRows; i++)
    {
        for (size_t j = 0; j < matrix.mCols - 1; j++)
        {
            os << matrix.mValues[i * matrix.mCols + j] << "\t";
        }
        os << matrix.mValues[(i + 1) * matrix.mCols - 1] << std::endl;
    }

    return os;
};
