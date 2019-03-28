//Container.cpp

#include <random>
#include <time.h>
#include <iostream>

#include "../include/Container.h"



Container::Container()
{
    srand(time(0));
}


void Container::FillVector()                            //TODO: Сделать переменные размера как поля класса
{

    for(size_t i = 0; i < large_size; i++)
    {
        if ( i < small_size )
        {
            m_small_vector.push_back( rand() % 101 + 1 );
        }
        /*
                if ( i < medium_size )
                {
                    m_medium_vector.push_back( rand() % 101 + 1 );
                }

                if ( i < large_size )
                {
                    m_large_vector.push_back( rand() % 101 + 1 );
                }
        */
    }

}


void Container::ShowVector()
{

    std::cout << "Small vector: " << std::endl;
    for(size_t i = 0; i < small_size; i++)
    {
        std::cout << m_small_vector[i] << " ";
    }
    std::cout << std::endl;

    /*

        std::cout << "Medium vector: " << std::endl;
        for(size_t i = 0; i < medium_size; i++)
        {
            std::cout << m_medium_vector[i] << " ";
        }
        std::cout << std::endl;



        std::cout << "Large vector: " << std::endl;
        for(size_t i = 0; i < large_size; i++)
        {
            std::cout << m_large_vector[i] << " ";
        }
        std::cout << std::endl;

    */

}


