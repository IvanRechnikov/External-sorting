#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
using namespace std;


template <typename T>
class standart_cmp
{
public:
    static bool less(const T& a, const T& b)
    {
        return a < b;
    }
};

//‘ункци€ сли€ни€ массива
//array - массив, который упор€дочен до middle, и после middle
//buffer - массив, размером не меньше чем array
template <typename T, typename cmp = standart_cmp<T> >
void merge(T* array, T* buffer, int left, int middle, int right)
{
    //»ндесы считывани€ чисел из array
    int it_left = 0;
    int it_right = 0;

    // ак только какой-либо из "итераторов" выходит за границу, прекращаем цикл
    while (left + it_left < middle && middle + it_right < right)
    {
        if (cmp::less(array[left + it_left], array[middle + it_right]))
        {
            buffer[it_left + it_right] = array[left + it_left];
            it_left++;
        }
        else
        {
            buffer[it_left + it_right] = array[middle + it_right];
            it_right++;
        }
    }

    //«аписываем оставшиес€ части, невыписанные из array
    while (left + it_left < middle)
    {
        buffer[it_left + it_right] = array[left + it_left];
        it_left++;
    }

    while (middle + it_right < right)
    {
        buffer[it_left + it_right] = array[middle + it_right];
        it_right++;
    }

    //¬ыписываем buffer в array
    for (int i = 0; i < it_left + it_right; i++)
        array[left + i] = buffer[i];
}

//array - массив
//buffer - буфер дл€ сортировки, размером не меньше, чем array
//left - нижн€€ граница, right - верхн€€
template <typename T, typename cmp = standart_cmp<T> >
void merge_sort(T* array, T* buffer, int left, int right)
{
    //ћассив единичного размера уже отсортированым считаетс€
    if (right - left <= 1)
    {
        return;
    }

    //»ндекс серединного элемента
    int middle = left + (right - left) / 2;

    //—ортируем половинки массива
    merge_sort(array, buffer, left, middle);
    merge_sort(array, buffer, middle, right);

    //—оставл€ем из двух отсортированных половинок
    //÷елый отсортированный массив
    merge<T, cmp>(array, buffer, left, middle, right);
}

#endif