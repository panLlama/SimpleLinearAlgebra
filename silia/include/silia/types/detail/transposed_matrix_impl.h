#ifndef SILIA__TYPES__DETAIL__TRANSPOSED_MATRIX_IMPL_H
#define SILIA__TYPES__DETAIL__TRANSPOSED_MATRIX_IMPL_H

#include <silia/types/detail/index_swap.h>
#include <silia/types/detail/raw_matrix.h>
#include <silia/types/detail/types_fwd.h>

namespace silia
{

namespace detail
{

template <size_t N, size_t M, typename T>
class TransposedMatrixImpl
{
  public:
    using index_type = size_t;
    friend Vector<M, T>;
    friend Matrix<M, N, T>;

    IndexSwap<M, N, T> operator[](index_type index)
    {
        return IndexSwap<M, N, T>(matrix_, index);
    }

    IndexSwap<M, N, T> operator[](index_type index) const
    {
        return IndexSwap<M, N, T>(matrix_, index);
    }

  private:
    TransposedMatrixImpl(RawMatrix<M, N, T>& matrix) : matrix_{matrix} {}
    RawMatrix<M, N, T>& matrix_;
};

}  // namespace detail

}  // namespace silia

#endif  // SILIA__TYPES__DETAIL__TRANSPOSED_MATRIX_IMPL_H
