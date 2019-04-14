#include "../include/Container.h"
#include <vector>
#include <algorithm>

#include <iostream>

void Container::BubbleSort()
{

    for(auto i = m_small_vector.begin(); i != m_small_vector.end(); i++) //auto &i : m_small_vector
    {
        for(auto j = m_small_vector.begin(); j != m_small_vector.end(); j++)
        {
            if(*i < *j)
            {
                std::swap(*i, *j);
            }
        }
    }

}


void Container::SelectionSort()
{
    auto sorted_position = m_small_vector.begin();

    while( sorted_position < m_small_vector.end() )
    {
        auto minimum_element = std::min_element(sorted_position, m_small_vector.end());
        std::swap(*minimum_element, *sorted_position);
        sorted_position++;
    }
}


std::vector<int>::iterator Container::GetPartition(std::vector<int>::iterator left_iterator, std::vector<int>::iterator right_iterator)
{
    auto pivot = left_iterator;

    for(auto i = left_iterator; i != right_iterator; i++)
    {
        if(*i < *right_iterator)
        {
            std::iter_swap(i, pivot);
            pivot++;
        }
    }

    std::iter_swap(pivot, right_iterator);
    return pivot;
}


void Container::PrivateQuickSort(std::vector<int>::iterator left_iterator, std::vector<int>::iterator right_iterator)
{
    int size = std::distance(left_iterator, right_iterator);
    if (size <= 1) return;

    auto m_iter = GetPartition(left_iterator, right_iterator);

    PrivateQuickSort(left_iterator, m_iter-1);
    PrivateQuickSort(m_iter, right_iterator);


}


void Container::QuickSort()
{
    PrivateQuickSort(m_small_vector.begin(), m_small_vector.end()-1);
}


void Container::InsertionSort()
{
    for (auto i = m_small_vector.begin() + 1; i != m_small_vector.end(); i++)  // 3 6 1 9
    {
        for (auto j = i; *j < *(j - 1) && j > m_small_vector.begin(); j--)
        {
            std::iter_swap(j, j - 1);
        }
    }
}
