#ifndef TSP_H
#define TSP_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>

// Klasa TSP (Travelling Salesman Problem)
// Odpowiada za reprezentację grafu i operacje na nim
class TSP {
public:
    std::vector<std::vector<int>> graph; // Macierz sąsiedztwa grafu
    int numCities;                       // Liczba miast (wierzchołków grafu)

    // Funkcja wczytująca dane grafu z pliku
    // Parametr:
    // - filename: nazwa pliku, z którego wczytany zostanie graf
    void loadFromFile(const std::string& filename);

    // Funkcja generująca losowy graf
    // Parametr:
    // - size: liczba miast (rozmiar grafu)
    void generateRandomGraph(int size);
};

#endif
