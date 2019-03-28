#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>


class Container
{
public:
    Container();
    void FillVector();
    void ShowVector();

    void BubbleSort();
    void QuickSort();
    void SelectionSort();

private:
    void PrivateQuickSort(std::vector<int>::iterator left_iterator, std::vector<int>::iterator right_iterator);

private:
    std::vector<int> m_small_vector;
    std::vector<int> m_medium_vector;
    std::vector<int> m_large_vector;

    const std::size_t large_size  = 100000000; //100 млн
    const std::size_t medium_size = 10000;
    const std::size_t small_size  = 10;
};

#endif // CONTAINER_H