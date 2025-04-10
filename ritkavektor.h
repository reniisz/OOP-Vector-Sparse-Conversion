#pragma once
#include "vektor.h"
#include <vector>
#include <stdexcept>

using namespace std; 

template <class T>
struct nonZero {
    T elem;
    int index;
};

template<class T>
class RitkaVektor {
public:
    RitkaVektor(int dim = 0) : dim(dim), elements() {
        if (dim > 0) {
            elements.push_back({ 1, 0 }); 
        }
    }
    RitkaVektor(T* t, int dim);
    RitkaVektor(const RitkaVektor& other) : dim(other.dim), elements(other.elements) {}
    ~RitkaVektor() {}

    RitkaVektor operator+(const RitkaVektor& other);
    RitkaVektor operator-(const RitkaVektor& other);
    double operator*(const RitkaVektor& other);
    double operator~();
    double operator%(const RitkaVektor& other);
    T operator[](int index) const;
    void addElement(int index, T value);
    operator Vektor<T>();

private:
    vector<nonZero<T>> elements;
    int dim;
};

template<class T>
RitkaVektor<T>::RitkaVektor(T* t, int dim) : dim(dim) {
    for (int i = 0; i < dim; ++i) {
        if (t[i] != 0) {
            elements.push_back({ t[i], i });
        }
    }
}

template<class T>
RitkaVektor<T> RitkaVektor<T>::operator+(const RitkaVektor& other) {
    if (dim != other.dim) throw runtime_error("meretelteres");
    vector<T> result(dim, 0);
    for (auto& e : elements) {
        result[e.index] += e.elem;
    }
    for (auto& e : other.elements) {
        result[e.index] += e.elem;
    }
    return RitkaVektor(result.data(), dim);
}

template<class T>
RitkaVektor<T> RitkaVektor<T>::operator-(const RitkaVektor& other) {
    if (dim != other.dim) throw runtime_error("meretelteres a kivonasban");
    vector<T> result(dim, 0);
    for (auto& e : elements) {
        result[e.index] = e.elem;
    }
    for (auto& e : other.elements) {
        result[e.index] -= e.elem;
    }
    return RitkaVektor(result.data(), dim);
}

template<class T>
double RitkaVektor<T>::operator*(const RitkaVektor& other) {
    if (dim != other.dim) throw runtime_error("meretelteres a skalarszorzatba");
    double result = 0;
    for (auto& e : elements) {
        for (auto& f : other.elements) {
            if (e.index == f.index) {
                result += e.elem * f.elem;
            }
        }
    }
    return result;
}

template<class T>
double RitkaVektor<T>::operator~() {
    double sum = 0;
    for (auto& e : elements) {
        sum += e.elem * e.elem;
    }
    return sqrt(sum);
}

template<class T>
double RitkaVektor<T>::operator%(const RitkaVektor& other) {
    return sqrt((*this - other) * (*this - other));
}

template<class T>
T RitkaVektor<T>::operator[](int index) const {
    if (index < 0 || index >= dim) throw runtime_error("Index hataron kivul");
    for (auto& e : elements) {
        if (e.index == index) {
            return e.elem;
        }
    }
    return 0;
}

template<class T>
void RitkaVektor<T>::addElement(int index, T value) {
    if (index < 0 || index >= dim) throw runtime_error("Index hataron kivul");
    for (auto& e : elements) {
        if (e.index == index) {
            e.elem = value;
            return;
        }
    }
    elements.push_back({ value, index });
}

template<class T>
RitkaVektor<T>::operator Vektor<T>() {
    Vektor<T> result(dim);
    for (auto& e : elements) {
        result.m_t[e.index] = e.elem;
    }
    return result;
}
