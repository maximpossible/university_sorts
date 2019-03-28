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


void Container::PrivateQuickSort(std::vector<int>::iterator left_iterator, std::vector<int>::iterator right_iterator)
{
    /*
    auto middle_iterator = ( left_iterator + std::distance(left_iterator, right_iterator) / 2 );
    auto l_iter = left_iterator;
    auto r_iter = right_iterator;

    while( l_iter <= r_iter)
    {
        while( *l_iter < *middle_iterator ) l_iter++;
        while( *r_iter > *middle_iterator ) r_iter--;
        std::cout << "LITER: " << *l_iter << "   RITER: " << *r_iter << std::endl;
        std::swap(*l_iter, *r_iter);


        l_iter++;
        r_iter--;
    //        if (l_iter <= r_iter)
    //        {
    //            std::swap(*l_iter, *r_iter);
    //            l_iter++;
    //            r_iter--;
    //        }


        //std::cout << std::distance(l_iter, r_iter) << " ";
    }


    //if( l_iter != m_small_vector.end() ) PrivateQuickSort(m_small_vector.begin(), middle_iterator);
    //if( r_iter != m_small_vector.begin()) PrivateQuickSort(middle_iterator + 1, m_small_vector.end());
    */


    /*
    /    **тута рабочий код

        auto middle_iterator = ( left_iterator + std::distance(left_iterator, right_iterator) / 2 );

        std::cout << "opor: " << *middle_iterator << std::endl << std::endl;


        auto l_iter = left_iterator;
        auto r_iter = right_iterator;

        while( l_iter < r_iter )
        {
            Container::ShowVector();
            while ( *l_iter < *middle_iterator) l_iter++;
            while ( *r_iter > *middle_iterator) r_iter--;

            if( l_iter < r_iter )
            {
                std::swap(*l_iter, *r_iter);
                l_iter++;
                r_iter--;
            }
        }



    */


   //    **тута рабочий код | ну такое

            auto middle_iterator = ( left_iterator + std::distance(left_iterator, right_iterator) / 2 );

            std::cout << "opor: " << *middle_iterator << std::endl << std::endl;


            auto l_iter = left_iterator;
            auto r_iter = right_iterator;

            while( l_iter < r_iter )
            {
                Container::ShowVector();
                while ( *l_iter < *middle_iterator) l_iter++;
                while ( *r_iter > *middle_iterator) r_iter--;

                if( l_iter <= r_iter )
                {
                    std::swap(*l_iter, *r_iter);
                    l_iter++;
                    r_iter--;
                }
            }







    /*
    //    **тута рабочий код

            //if (left_iterator >= right_iterator ) return;

            auto middle_iterator = ( left_iterator + std::distance(left_iterator, right_iterator) / 2 );

            std::cout << "opor: " << *middle_iterator << std::endl << std::endl;


            auto l_iter = left_iterator;
            auto r_iter = right_iterator;

            while( l_iter < r_iter )
            {
                Container::ShowVector();
                while ( *l_iter < *middle_iterator) l_iter++;
                while ( *r_iter > *middle_iterator) r_iter--;

                if( l_iter < r_iter )
                {
                    std::swap(*l_iter, *r_iter);
                    l_iter++;
                    r_iter--;
                }
            }

    */
    // std::cout << "liter: " << *l_iter << "     riter: " << *r_iter << std::endl;

    //if (r_iter > m_small_vector.begin()) PrivateQuickSort(m_small_vector.begin(), r_iter);
    // PrivateQuickSort(l_iter, right_iterator);



    /*

        const auto middle_iterator = ( left_iterator + std::distance(left_iterator, right_iterator) / 2 );
        auto middle_value = *middle_iterator;

        std::cout << "opor: " << *middle_iterator << std::endl << std::endl;


        auto l_iter = left_iterator;
        auto r_iter = right_iterator;

        while( l_iter < r_iter )
        {
            Container::ShowVector();
            while ( *l_iter < *middle_iterator) l_iter++;
            while ( *r_iter >= *middle_iterator) r_iter--;

            if( l_iter < r_iter )
            {
                std::swap(*l_iter, *r_iter);
                l_iter++;
                r_iter--;
            }
        }

        //middle_iterator = std::find(left_iterator, right_iterator, middle_value);
        std::cout << "mi     " << *middle_iterator << "     " << std::endl;



        //if(r_iter > m_small_vector.begin()) PrivateQuickSort(m_small_vector.begin(), middle_iterator);
        //if(l_iter < m_small_vector.end()) PrivateQuickSort(middle_iterator + 1, )

        //if(middle_iterator != m_small_vector.begin()) PrivateQuickSort(m_small_vector.begin(), middle_iterator);
        //if(middle_iterator != m_small_vector.end() - 1) PrivateQuickSort(middle_iterator + 1, m_small_vector.end() - 1);


       // if(r_iter > m_small_vector.begin()) PrivateQuickSort(m_small_vector.begin(), r_iter);
       // if(l_iter < m_small_vector.end() - 1) PrivateQuickSort(l_iter, m_small_vector.end() - 1);


    */
}
//

void Container::QuickSort()
{

    //Container::PrivateQuickSort( m_small_vector.begin(), m_small_vector.end() );
    PrivateQuickSort(m_small_vector.begin(), m_small_vector.end() - 1);
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
