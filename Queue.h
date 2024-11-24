#ifndef QUEUE_H
#define QUEUE_H

#include <vector>

// Szablon klasy Queue - implementacja kolejki FIFO (First-In, First-Out)
template <typename T>
class Queue {
private:
    std::vector<T> data;      // Wektor przechowujący elementy kolejki
    int frontIndex = 0;       // Indeks elementu znajdującego się na początku kolejki
    int backIndex = 0;        // Indeks następnego wolnego miejsca na końcu kolejki

public:
    // Funkcja dodająca nowy element na koniec kolejki
    void push(const T& value) {
        if (backIndex == data.size()) {
            // Jeśli osiągnięto rozmiar wektora, dodaj nowy element
            data.push_back(value);
        } else {
            // Jeśli miejsce jest dostępne, nadpisz istniejący element
            data[backIndex] = value;
        }
        ++backIndex; // Przesuń wskaźnik końca kolejki
    }

    // Funkcja usuwająca element z początku kolejki
    void pop() {
        if (!empty()) {
            // Przesuń wskaźnik początku kolejki
            ++frontIndex;
        }
    }

    // Funkcja zwracająca element na początku kolejki
    T front() const {
        return data[frontIndex];
    }

    // Funkcja sprawdzająca, czy kolejka jest pusta
    bool empty() const {
        return frontIndex == backIndex;
    }
};

#endif
