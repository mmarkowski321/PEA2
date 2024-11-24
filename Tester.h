#ifndef TESTER_H
#define TESTER_H

#include "TSP.h"
#include "TSPSolver.h"
#include <vector>
#include <string>

// Klasa Tester - odpowiedzialna za przeprowadzanie testów algorytmów TSP
class Tester {
public:
    // Funkcja testująca algorytmy na danych z plików testowych
    // Parametry:
    // - testFiles: lista nazw plików testowych, które zawierają dane grafów
    void testCorrectnessFromFiles(const std::vector<std::string>& testFiles);

    // Funkcja testująca algorytmy na wygenerowanych grafach o różnych rozmiarach
    // Parametry:
    // - minN: minimalny rozmiar grafu
    // - numIterations: liczba testów dla każdego rozmiaru grafu
    void testForDifferentNFromConfig(int minN, int numIterations);
};

#endif
