#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include "Funnel.h"


class Container
{
public:
    Container();
    void FillVector();
    void ShowVector();

    void BubbleSort();
    void QuickSort();
    void SelectionSort();
    void InsertionSort();
    void MergeSort();
    void FunnelSort();

private:
    void PrivateQuickSort(std::vector<int>::iterator left_iterator, std::vector<int>::iterator right_iterator);
    std::vector<int>::iterator GetPartition(std::vector<int>::iterator left_iterator, std::vector<int>::iterator right_iterator);

    void PrivateMergeSort(std::vector<int>::iterator left_iterator, std::vector<int>::iterator right_iterator);
    void Merge(std::vector<int>::iterator left_iterator, std::vector<int>::iterator middle_iterator, std::vector<int>::iterator right_iterator);

private:
    std::vector<int> m_small_vector;
    std::vector<int> m_medium_vector;
    std::vector<int> m_large_vector;

    const std::size_t large_size  = 100000000; //100 млн
    const std::size_t medium_size = 10000;
    const std::size_t small_size  = 10;

    Funnel funnel;
};

#endif // CONTAINER_H

