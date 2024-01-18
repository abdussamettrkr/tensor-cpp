#pragma once
#include <vector>
#include <iostream>

class Shape
{
private:
    std::vector<int> shape;
    int numDimensions;
    int totalElements;

public:
    template <typename Iterable>
    Shape(Iterable &arraylike);

    int operator[](int index);

    int size();
    std::vector<int> dims();
    int ndims();
    friend std::ostream &operator<<(std::ostream &os, const Shape &obj);
};

template <typename Iterable>
Shape::Shape(Iterable &arraylike)
{
    this->numDimensions = 0;
    this->totalElements = 1;
    bool isEmpty = true;
    for (auto &dim : arraylike)
    {
        isEmpty = false;
        shape.push_back(dim);
        numDimensions++;
        totalElements *= dim;
    }
    this->totalElements = (isEmpty) ? 0:totalElements;
}