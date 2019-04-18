//Funnel.cpp

#include "../include/Funnel.h"

#include <vector>
#include <list>
#include <iostream>


void Funnel::FunnelSort(std::vector<int>& container)
{
    FillBuffer(container);
    Merge();
    FillContainer(container);
}


void Funnel::FillBuffer(const std::vector<int>& container)
{
    bool pushed = 0;
    buffer.push_back(std::list<int> {});

    for (auto i : container)
    {
        for (auto& j : buffer)
        {
            pushed = 0;

            if (i <= j.front())
            {
                j.push_front(i);
                pushed = 1;
                break;
            }
            else if(i >= j.back())
            {
                j.push_back(i);
                pushed = 1;
                break;
            }
        }

        if (!pushed)
        {
            buffer.push_back(std::list<int> {i});
        }
    }
}


void Funnel::Merge()
{
    while (buffer.size() != 1)
    {
        std::list<int> temp;
        while (buffer.back().size() > 0)
        {
            if (buffer.front().front() < buffer.back().front())
            {
                temp.push_back(buffer.front().front());
                buffer.front().pop_front();

            }
            else if (buffer.back().front() <= buffer.front().front())
            {
                temp.push_back(buffer.back().front());
                buffer.back().pop_front();

            }
            if (buffer.front().size() == 0 || buffer.back().size() == 0)
            {
                while (buffer.front().size() > 0)
                {

                    temp.push_back(buffer.front().front());
                    buffer.front().pop_front();
                }
                while (buffer.back().size() > 0)
                {

                    temp.push_back(buffer.back().front());
                    buffer.back().pop_front();
                }
            }
        }

        buffer.pop_back();
        buffer.pop_front();

        buffer.push_back(temp);
    }
}


void Funnel::Show()
{
    for (auto i : buffer)
    {
        for (auto j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}


void Funnel::FillContainer(std::vector<int>& container)
{
    container.clear();
    for (auto i : buffer)
    {
        for (auto j : i)
        {
            container.push_back(j);
        }
    }
}
