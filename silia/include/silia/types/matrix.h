#ifndef SILIA__TYPES__MATRIX_H
#define SILIA__TYPES__MATRIX_H

#include <silia/types/detail/matrix_detail.h>

#include <cstddef>
#include <type_traits>

namespace silia
{

template <size_t N, size_t M, typename Derived, typename V>
class Matrix
{
  public:
    using index_type = size_t;

    template <typename T = Derived>
    auto operator[](index_type index) -> decltype(std::declval<T>()[0])
    {
        static_assert(std::is_same<T, Derived>::value,
                      "Only the default template argument is allowed for Matrix::operator[]");

        return static_cast<T*>(this)->operator[](index);
    }

    template <typename T = Derived>
    auto operator[](index_type index) const -> decltype(std::declval<T const>()[0])
    {
        static_assert(std::is_same<T, Derived>::value,
                      "Only the default template argument is allowed for Matrix::operator[]");

        return static_cast<T const*>(this)->operator[](index);
    }

    Matrix(V const (&list)[N][M]) : matrix_{}
    {
        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 0; j < N; ++j)
            {
                matrix_[i][j] = list[i][j];
            }
        }
    }

    Matrix() : matrix_{} {}

  protected:
    detail::RawMatrix<N, M, V> matrix_;
};

}  // namespace silia

#endif  // SILIA__TYPES__MATRIX_H
