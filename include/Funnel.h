//Funnel.h
#ifndef FUNNEL_H
#define FUNNEL_H

#include <list>
#include <vector>

class Funnel
{
public:
    void FunnelSort(std::vector<int>& container);

private:
    void FillBuffer(const std::vector<int>& container);
    void Merge();
    void FillContainer(std::vector<int>& container);

    void Show();

private:
    std::list<std::list<int> > buffer;

};



#endif // FUNNEL_H
