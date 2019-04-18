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

// 64129771
// 6412 9771
// 64 12 97 71
// 46 12 79 17
// 1 2 4 6  79 17
// 1 2 4 6  1 7 7 9
// 1 1 2 4 6 7 7 9
//
//func
//{
//    if (a - b != 1) func(a, (b-a)/2);
//    if(a > b) swap(a, b);
//
//
//}
//
//func(a, (b-a)/2);
//func((b-a)/2 + 1, b);

//void Merge(std::vector<int>::iterator left, std::vector<int>::iterator right);

void Container::Merge(std::vector<int>::iterator left_iterator, std::vector<int>::iterator middle_iterator, std::vector<int>::iterator right_iterator)
{
    auto l_iter = left_iterator;
    auto r_iter   = middle_iterator;

    std::vector<int> temp;

    while (l_iter != middle_iterator && r_iter != right_iterator)
    {
        if (*l_iter < *r_iter)
        {
            temp.push_back(*l_iter);
            l_iter++;
        }
        if (*l_iter > *r_iter)
        {
            temp.push_back(*r_iter);
            r_iter++;
        }
    }

    temp.insert(temp.end(), l_iter, middle_iterator);
    temp.insert(temp.end(), r_iter, right_iterator);

    std::move(temp.begin(), temp.end(), left_iterator);

//    for(auto i : temp)
//    {
//        std::cout << i << " ";
//    }
//    std::cout << std::endl << std::endl;

}

void Container::PrivateMergeSort(std::vector<int>::iterator left_iterator, std::vector<int>::iterator right_iterator)  // 1 3 4 5 6
{
    size_t distance = std::distance(left_iterator, right_iterator);
    if (distance < 2)
    {
        return;
    }

    auto middle_iterator = std::next(left_iterator, distance / 2);

    PrivateMergeSort(left_iterator, middle_iterator);
    PrivateMergeSort(middle_iterator, right_iterator); //middle+1 ?

    Merge(left_iterator, middle_iterator, right_iterator);








//    if (std::distance(left_iterator, right_iterator) == 0)
//    {
//        std::vector<int> ret = {*left_iterator};
//        return ret;
//    }
//    if (std::distance(left_iterator, right_iterator) == 1)
//    {
//        if (*left_iterator > *right_iterator)
//        {
//            std::vector<int> ret = {*right_iterator, *left_iterator};
//            return ret;
//        }
//        else
//        {
//            std::vector<int> ret = {*left_iterator, *right_iterator};
//            return ret;
//        }
//    }
//
//    auto pivot = left_iterator + ( std::distance(left_iterator, right_iterator) / 2 - 1);
//
//
//
//    std::vector<int> left = PrivateMergeSort(left_iterator, pivot);
//    std::vector<int> right = PrivateMergeSort(pivot + 1, right_iterator);
//
//
//    std::vector<int> buffer;
//
//    for (auto i = left.begin(), j = right.begin(); i != left.end() && j != right.end(); )
//    {
//        if (*i < *j)
//        {
//            buffer.push_back(*i);
//            i++;
//        }
//        else
//        {
//            buffer.push_back(*j);
//            j++;
//        }
//
//    }
//
//
//












//    for (auto i = left_iterator, j = pivot; i != pivot && j != right_iterator;)   // 1 4 9    5 6 7
//    {
//        if(*i < *j)
//        {
//            buffer.push_back(*i);
//            i++;
//        }
//        else
//        {
//            buffer.push_back(*j);
//            j++;
//        }
//    }


//    for(auto i : buffer)
//    {
//        std::cout << std::endl << i << " ";
//    }
//    std::cout << std::endl;


//    for(auto i = left_iterator; i != right_iterator; i++)
//    {
//        //*i = buffer.back();  //<--
//        //buffer.pop_back();
//    }

//    return buffer;
}

void Container::MergeSort()
{
    PrivateMergeSort(m_small_vector.begin(), m_small_vector.end());
}


void Container::FunnelSort()
{
    funnel.FunnelSort(m_small_vector);
}
