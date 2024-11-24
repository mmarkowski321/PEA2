#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <functional>
#include <algorithm>

// Szablon klasy PriorityQueue
// T - typ danych przechowywanych w kolejce
// Comparator - funktor do porównywania elementów (domyślnie std::greater<T>)
template <typename T, typename Comparator = std::greater<T>>
class PriorityQueue {
private:
    std::vector<T> data;      // Wektor przechowujący elementy kolejki
    Comparator compare;       // Obiekt funktora do porównywania elementów

    // Funkcja do porządkowania elementów od dołu w strukturze kopca
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2; // Indeks rodzica
            if (compare(data[parent], data[index])) {
                std::swap(data[parent], data[index]); // Zamiana miejsc, jeśli rodzic jest "mniejszy"
                index = parent; // Przejście do rodzica
            } else {
                break;
            }
        }
    }

    // Funkcja do porządkowania elementów od góry w strukturze kopca
    void heapifyDown(int index) {
        int size = data.size();
        while (true) {
            int left = 2 * index + 1;   // Indeks lewego dziecka
            int right = 2 * index + 2; // Indeks prawego dziecka
            int smallest = index;      // Zakładamy, że obecny indeks jest najmniejszy

            // Sprawdzenie lewego dziecka
            if (left < size && compare(data[smallest], data[left])) {
                smallest = left;
            }
            // Sprawdzenie prawego dziecka
            if (right < size && compare(data[smallest], data[right])) {
                smallest = right;
            }
            // Jeśli najmniejszy element to nie obecny indeks, zamień elementy
            if (smallest != index) {
                std::swap(data[index], data[smallest]);
                index = smallest; // Kontynuacja porządkowania dla zmienionego indeksu
            } else {
                break; // Jeśli kopiec jest w porządku, zakończ
            }
        }
    }

public:
    // Funkcja dodająca nowy element do kolejki
    void push(const T& value) {
        data.push_back(value);          // Dodaj element na koniec wektora
        heapifyUp(data.size() - 1);     // Przywróć właściwości kopca
    }

    // Funkcja usuwająca element o najwyższym priorytecie
    void pop() {
        if (!empty()) {
            std::swap(data[0], data.back()); // Zamień pierwszy i ostatni element
            data.pop_back();                // Usuń ostatni element
            if (!empty()) {
                heapifyDown(0);             // Przywróć właściwości kopca
            }
        }
    }

    // Funkcja zwracająca element o najwyższym priorytecie
    T top() const {
        return data[0]; // Zwraca pierwszy element wektora
    }

    // Funkcja sprawdzająca, czy kolejka jest pusta
    bool empty() const {
        return data.empty();
    }
};

#endif
