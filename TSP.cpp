#include "TSP.h"
#include <iostream>
#include <fstream>
#include <random>

// Funkcja wczytująca graf z pliku
void TSP::loadFromFile(const std::string& filename) {
    // Próba otwarcia pliku
    std::ifstream file(filename);
    if (!file.is_open()) {
        // Jeśli pliku nie udało się otworzyć, wypisz komunikat i zakończ funkcję
        std::cerr << "Cannot open file: " << filename << std::endl;
        return;
    }

    // Wczytaj liczbę miast (wierzchołków grafu)
    file >> numCities;

    // Zainicjalizuj macierz sąsiedztwa o rozmiarze numCities x numCities
    graph.assign(numCities, std::vector<int>(numCities));

    // Wczytaj wartości z pliku do macierzy sąsiedztwa
    for (int i = 0; i < numCities; ++i) {
        for (int j = 0; j < numCities; ++j) {
            file >> graph[i][j];
        }
    }

    // Zamknij plik
    file.close();
}

// Funkcja generująca losowy graf
void TSP::generateRandomGraph(int size) {
    // Ustaw liczbę miast
    numCities = size;

    // Zainicjalizuj macierz sąsiedztwa o rozmiarze size x size
    graph.assign(numCities, std::vector<int>(numCities));

    // Generator liczb losowych
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100); // Zakres wag krawędzi: 1-100

    // Wypełnij macierz sąsiedztwa losowymi wagami
    for (int i = 0; i < numCities; ++i) {
        for (int j = 0; j < numCities; ++j) {
            // Dla krawędzi do samego siebie ustaw 0
            graph[i][j] = (i == j) ? 0 : dist(gen);
        }
    }
}
