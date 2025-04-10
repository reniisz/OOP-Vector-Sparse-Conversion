#pragma once

#include <cmath>
#include <stdexcept>

template<class T>
class RitkaVektor;

template<class T>
class Vektor {
public:
    Vektor() : m_t(nullptr), m_dim(0) {}
    Vektor(int dim);
    Vektor(T* t, int dim);
    Vektor(const Vektor& other);
    ~Vektor();

    Vektor operator+(const Vektor& other);
    Vektor operator-(const Vektor& other);
    double operator*(const Vektor& other);
    double operator~();
    double operator%(const Vektor& other);
    T operator[](int index) const;
    operator RitkaVektor<T>();

private:
    T* m_t;
    int m_dim;

    friend class RitkaVektor<T>;
};

template<class T>
Vektor<T>::Vektor(int dim) : m_dim(dim), m_t(new T[dim]) {
    for (int i = 0; i < dim; ++i) {
        m_t[i] = 1;
    }
}

template<class T>
Vektor<T>::Vektor(T* t, int dim) : m_dim(dim), m_t(new T[dim]) {
    for (int i = 0; i < dim; ++i) {
        m_t[i] = t[i];
    }
}

template<class T>
Vektor<T>::Vektor(const Vektor<T>& other) : m_dim(other.m_dim), m_t(new T[other.m_dim]) {
    for (int i = 0; i < m_dim; ++i) {
        m_t[i] = other.m_t[i];
    }
}

template<class T>
Vektor<T>::~Vektor() {
    delete[] m_t;
}

template<class T>
Vektor<T> Vektor<T>::operator+(const Vektor<T>& other) {
    if (m_dim != other.m_dim) throw "meretelteres";
    Vektor<T> result(m_dim);
    for (int i = 0; i < m_dim; ++i) {
        result.m_t[i] = m_t[i] + other.m_t[i];
    }
    return result;
}

template<class T>
Vektor<T> Vektor<T>::operator-(const Vektor<T>& other) {
    if (m_dim != other.m_dim) throw "meretelteres a kivonasban";
    Vektor<T> result(m_dim);
    for (int i = 0; i < m_dim; ++i) {
        result.m_t[i] = m_t[i] - other.m_t[i];
    }
    return result;
}

template<class T>
double Vektor<T>::operator*(const Vektor<T>& other) {
    if (m_dim != other.m_dim) throw "meretelteres a skalarszorzatba";
    double sum = 0;
    for (int i = 0; i < m_dim; ++i) {
        sum += m_t[i] * other.m_t[i];
    }
    return sum;
}

template<class T>
double Vektor<T>::operator~() {
    double sum = 0;
    for (int i = 0; i < m_dim; ++i) {
        sum += m_t[i] * m_t[i];
    }
    return std::sqrt(sum);
}

template<class T>
double Vektor<T>::operator%(const Vektor<T>& other) {
    Vektor<T> diff = *this - other;
    return ~diff;
}

template<class T>
T Vektor<T>::operator[](int index) const {
    if (index < 0 || index >= m_dim) {
        throw "Index out of bounds";
    }
    return m_t[index];
}

template<class T>
Vektor<T>::operator RitkaVektor<T>() {
    RitkaVektor<T> ritka(m_dim);
    for (int i = 0; i < m_dim; ++i) {
        if (m_t[i] != 0) {
            ritka.addElement(i, m_t[i]);
        }
    }
    return ritka;
}
