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


void Container::Merge(std::vector<int>::iterator left_iterator, std::vector<int>::iterator middle_iterator, std::vector<int>::iterator right_iterator)
{
    auto l_iter = left_iterator;
    auto r_iter = middle_iterator;

    std::vector<int> buffer;

    while (l_iter != middle_iterator && r_iter != right_iterator)
    {
        buffer.push_back( *l_iter < *r_iter ? *l_iter++ : *r_iter++ );
    }
    while (l_iter != middle_iterator) buffer.push_back(*l_iter++);
    while (r_iter != right_iterator)  buffer.push_back(*r_iter++);

    std::copy(buffer.begin(), buffer.end(), left_iterator);
}


void Container::PrivateMergeSort(std::vector<int>::iterator left_iterator, std::vector<int>::iterator right_iterator)  // 1 3 4 5 6
{
    size_t distance = std::distance(left_iterator, right_iterator);
    auto middle_iterator = std::next(left_iterator, distance / 2);

    if (distance > 1)
    {
        PrivateMergeSort(left_iterator, middle_iterator);
        PrivateMergeSort(middle_iterator, right_iterator);
        Merge(left_iterator, middle_iterator, right_iterator);
    }

}

void Container::MergeSort()
{
    PrivateMergeSort(m_small_vector.begin(), m_small_vector.end());
}


void Container::FunnelSort()
{
    funnel.FunnelSort(m_small_vector);
}
