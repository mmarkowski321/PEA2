#include "Tester.h"
#include <chrono>
#include <iostream>
#include <fstream>

// Funkcja testująca poprawność algorytmów na podstawie danych z plików testowych
void Tester::testCorrectnessFromFiles(const std::vector<std::string>& testFiles) {
    for (const auto& filename : testFiles) {
        TSP tsp;
        // Wczytaj dane z pliku
        std::cout << "\nLoading data from file: " << filename << std::endl;
        tsp.loadFromFile(filename);

        if (!tsp.graph.empty()) {
            // Jeśli dane zostały poprawnie wczytane, przeprowadź testy
            std::cout << "\nResults for file " << filename << "\n";

            // Test algorytmu BFS
            auto bfsStart = std::chrono::high_resolution_clock::now();
            int bfsResult = TSPSolver::bfsTSP(tsp);
            auto bfsEnd = std::chrono::high_resolution_clock::now();
            double bfsTime = std::chrono::duration_cast<std::chrono::microseconds>(bfsEnd - bfsStart).count();
            std::cout << "BFS: Cost = " << bfsResult << ", Time = " << bfsTime << " us\n";

            // Test algorytmu DFS
            auto dfsStart = std::chrono::high_resolution_clock::now();
            int dfsResult = TSPSolver::dfsTSP(tsp);
            auto dfsEnd = std::chrono::high_resolution_clock::now();
            double dfsTime = std::chrono::duration_cast<std::chrono::microseconds>(dfsEnd - dfsStart).count();
            std::cout << "DFS: Cost = " << dfsResult << ", Time = " << dfsTime << " us\n";

            // Test algorytmu BestFS
            auto bestfsStart = std::chrono::high_resolution_clock::now();
            int bestfsResult = TSPSolver::bestfsTSP(tsp);
            auto bestfsEnd = std::chrono::high_resolution_clock::now();
            double bestfsTime = std::chrono::duration_cast<std::chrono::microseconds>(bestfsEnd - bestfsStart).count();
            std::cout << "BestFS: Cost = " << bestfsResult << ", Time = " << bestfsTime << " us\n";
        } else {
            // Jeśli nie udało się wczytać danych, pomiń plik
            std::cout << "File skipped: " << filename << " (error while loading)." << std::endl;
        }
    }
}

// Funkcja testująca algorytmy dla różnych rozmiarów grafów
void Tester::testForDifferentNFromConfig(int minN, int numIterations) {
    const int NUM_TESTS = numIterations; // Liczba powtórzeń dla każdego rozmiaru grafu
    std::ofstream file("results.csv");

    // Sprawdzenie, czy można otworzyć plik do zapisu wyników
    if (!file.is_open()) {
        std::cerr << "Cannot open file for writing results!" << std::endl;
        return;
    }

    // Nagłówki kolumn w pliku wyników
    file << "Size;Test_Number;BFS;DFS;BestFS\n";

    // Testy dla różnych rozmiarów grafów (minN do minN + 6)
    for (int n = minN; n < minN + 7; ++n) {
        double totalBFSTime = 0;   // Łączny czas dla BFS
        double totalDFSTime = 0;   // Łączny czas dla DFS
        double totalBestFSTime = 0; // Łączny czas dla BestFS

        for (int test = 1; test <= NUM_TESTS; ++test) {
            TSP tsp;
            // Generowanie losowego grafu o rozmiarze n
            tsp.generateRandomGraph(n);

            // Test algorytmu BFS
            auto bfsStart = std::chrono::high_resolution_clock::now();
            int bfsResult = TSPSolver::bfsTSP(tsp);
            auto bfsEnd = std::chrono::high_resolution_clock::now();
            double bfsTime = std::chrono::duration_cast<std::chrono::microseconds>(bfsEnd - bfsStart).count();

            // Test algorytmu DFS
            auto dfsStart = std::chrono::high_resolution_clock::now();
            int dfsResult = TSPSolver::dfsTSP(tsp);
            auto dfsEnd = std::chrono::high_resolution_clock::now();
            double dfsTime = std::chrono::duration_cast<std::chrono::microseconds>(dfsEnd - dfsStart).count();

            // Test algorytmu BestFS
            auto bestfsStart = std::chrono::high_resolution_clock::now();
            int bestfsResult = TSPSolver::bestfsTSP(tsp);
            auto bestfsEnd = std::chrono::high_resolution_clock::now();
            double bestfsTime = std::chrono::duration_cast<std::chrono::microseconds>(bestfsEnd - bestfsStart).count();

            // Zapis wyników pojedynczego testu do pliku
            file << n << ";" << test << ";" << bfsTime << ";" << dfsTime << ";" << bestfsTime << "\n";

            // Sumowanie czasów dla obliczenia średniej
            totalBFSTime += bfsTime;
            totalDFSTime += dfsTime;
            totalBestFSTime += bestfsTime;
        }

        // Obliczanie średnich czasów dla każdego algorytmu
        double avgBFSTime = totalBFSTime / NUM_TESTS;
        double avgDFSTime = totalDFSTime / NUM_TESTS;
        double avgBestFSTime = totalBestFSTime / NUM_TESTS;

        // Wyświetlenie wyników w konsoli
        std::cout << "Size = " << n << ": avg BFS time = " << avgBFSTime << " us, "
                  << "DFS = " << avgDFSTime << " us, "
                  << "BestFS = " << avgBestFSTime << " us\n";
    }

    // Zamknięcie pliku wyników
    file.close();
    std::cout << "Results saved to file results.csv" << std::endl;
}
