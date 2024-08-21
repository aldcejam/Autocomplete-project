#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>

template <typename T>
class List {
protected:
    std::vector<T> itens;

public:
    void insert(const T& item) {
        itens.push_back(item);
    }

    size_t size() const {
        return itens.size();
    }

    void print() const {
        for (const auto &item : itens) {
            std::cout << item << std::endl;
        }
    }

    T& operator[](size_t index) {
        return itens[index];
    }

    const T& operator[](size_t index) const {
        return itens[index];
    }
};

#endif // LIST_H
