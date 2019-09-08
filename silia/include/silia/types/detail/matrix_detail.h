#ifndef SILIA__TYPES__DETAIL__MATRIX_DETAIL_H
#define SILIA__TYPES__DETAIL__MATRIX_DETAIL_H

#include <array>
#include <cassert>
#include <memory>

namespace silia
{
template <size_t N, size_t M, typename T = double>
Matrix<N, M, T> MakeMatrix();

template <size_t N, typename T = double>
Vector<N, T> MakeVector();

namespace detail
{

template <size_t N, typename T>
class VectorImpl : public Vector<N, T>
{
  public:
    using BaseType = Vector<N, T>;
    using ValueType = T;

    VectorImpl(T const (&list)[N])
    {
        for (size_t i = 0; i < N; ++i)
        {
            BaseType::matrix_[i][0] = list[i];
        }
    }

    IndexableScalar<N, T> operator[](typename BaseType::index_type index)
    {
        return IndexableScalar<N, T>(BaseType::matrix_[index][0]);
    }

    IndexableScalarConst<N, T> operator[](typename BaseType::index_type index) const
    {
        return IndexableScalarConst<N, T>(BaseType::matrix_[index][0]);
    }

  private:
    VectorImpl() {}

    friend Vector<N, T> MakeVector<N, T>();
};

template <size_t N, size_t M, typename T>
class MatrixImpl : public Matrix<N, M, T>
{
  public:
    using BaseType = Matrix<N, M, T>;
    using ValueType = std::array<T, M>;
    using BaseType::MatrixType;

    std::array<T, M>& operator[](typename BaseType::index_type index)
    {
        return BaseType::matrix_[index];
    }

    std::array<T, M> const& operator[](typename BaseType::index_type index) const
    {
        return BaseType::matrix_[index];
    }

  private:
    MatrixImpl() {}

    friend Matrix<N, M, T> MakeMatrix<N, M, T>();
};
}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__MATRIX_DETAIL_H