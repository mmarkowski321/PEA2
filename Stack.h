#ifndef STACK_H
#define STACK_H

#include <vector>

// Szablon klasy Stack - implementacja stosu LIFO (Last-In, First-Out)
template <typename T>
class Stack {
private:
    std::vector<T> data; // Wektor przechowujący elementy stosu

public:
    // Funkcja dodająca nowy element na szczyt stosu
    void push(const T& value) {
        data.push_back(value); // Dodaj element na koniec wektora
    }

    // Funkcja usuwająca element ze szczytu stosu
    void pop() {
        if (!empty()) {
            data.pop_back(); // Usuń ostatni element wektora
        }
    }

    // Funkcja zwracająca element znajdujący się na szczycie stosu
    T top() const {
        return data.back(); // Zwróć ostatni element wektora
    }

    // Funkcja sprawdzająca, czy stos jest pusty
    bool empty() const {
        return data.empty(); // Zwróć true, jeśli wektor jest pusty
    }
};

#endif
