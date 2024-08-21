#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <vector>
#include <functional>
#include "./List.h"

template <typename T>
class SortedList : public List<T>
{
public:
    void sort() {
        quickSort(0, this->itens.size() - 1);
    }

    void sort(std::function<bool(const T&, const T&)> compare) {
        quickSort(0, this->itens.size() - 1, compare);
    }

private:
    void quickSort(int begin, int end) {
        if (begin < end) {
            int pivoIndex = partition(begin, end);
            quickSort(begin, pivoIndex - 1);
            quickSort(pivoIndex + 1, end);
        }
    }

    void quickSort(int begin, int end, std::function<bool(const T&, const T&)> compare) {
        if (begin < end) {
            int pivoIndex = partition(begin, end, compare);
            quickSort(begin, pivoIndex - 1, compare);
            quickSort(pivoIndex + 1, end, compare);
        }
    }

    int partition(int begin, int end) {
        T pivo = this->itens[end];
        int i = begin - 1;

        for (int j = begin; j < end; ++j) {
            if (this->itens[j] <= pivo) {
                i++;
                swap(i, j);
            }
        }
        swap(i + 1, end);
        return i + 1;
    }

    int partition(int begin, int end, std::function<bool(const T&, const T&)> compare) {
        T pivo = this->itens[end];
        int i = begin - 1;

        for (int j = begin; j < end; ++j) {
            if (compare(this->itens[j], pivo)) {
                i++;
                swap(i, j);
            }
        }
        swap(i + 1, end);
        return i + 1;
    }

    void swap(int i, int j) {
        T temp = this->itens[i];
        this->itens[i] = this->itens[j];
        this->itens[j] = temp;
    }
};

#endif // SORTED_LIST_H
