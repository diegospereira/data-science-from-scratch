#pragma once
#include <iostream>

class Matrix
{
private:
    friend std::ostream &operator<<(std::ostream &, const Matrix &);

    size_t mRows, mCols;
    double *mValues;

public:
    Matrix();

    Matrix(size_t, size_t);

    Matrix(size_t, size_t, const double *);

    ~Matrix();

    size_t size() const;
    size_t numRows() const;
    size_t numCols() const;

    static Matrix like(const Matrix &);
    static Matrix copy(const Matrix &);

    // Unary
    friend Matrix operator+(const Matrix &);
    friend Matrix operator-(const Matrix &);

    // Arithmetic
    friend Matrix operator+(const Matrix &, const Matrix &);
    friend Matrix operator-(const Matrix &, const Matrix &);
    friend Matrix operator*(const Matrix &, const Matrix &);
    friend Matrix operator*(const double, const Matrix &);
    friend Matrix operator*(const Matrix &, const double);
};
