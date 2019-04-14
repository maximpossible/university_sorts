#include "include/Container.h"


int main()
{
    Container a;
    a.FillVector();

    a.ShowVector();

    //a.BubbleSort();

    //a.QuickSort();

    //a.SelectionSort();

    //a.InsertionSort();

    a.MergeSort();
    a.ShowVector();



    return 0;
}
