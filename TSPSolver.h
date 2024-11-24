#ifndef TSP_SOLVER_H
#define TSP_SOLVER_H

#include "TSP.h"
#include "Queue.h"           // Implementacja kolejki FIFO
#include "Stack.h"           // Implementacja stosu LIFO
#include "PriorityQueue.h"   // Implementacja kolejki priorytetowej
#include <tuple>             // Typ std::tuple używany w BestFS
#include <algorithm>         // std::find do sprawdzania odwiedzonych miast

// Klasa TSPSolver - implementacja algorytmów dla problemu TSP
class TSPSolver {
public:
    // Algorytm BFS (Breadth-First Search) dla problemu TSP
    // Parametr:
    // - tsp: obiekt klasy TSP zawierający graf do przetworzenia
    // Zwraca:
    // - minimalny koszt cyklu Hamiltona
    static int bfsTSP(const TSP& tsp);

    // Algorytm DFS (Depth-First Search) dla problemu TSP
    // Parametr:
    // - tsp: obiekt klasy TSP zawierający graf do przetworzenia
    // Zwraca:
    // - minimalny koszt cyklu Hamiltona
    static int dfsTSP(const TSP& tsp);

    // Algorytm BestFS (Best-First Search) dla problemu TSP
    // Parametr:
    // - tsp: obiekt klasy TSP zawierający graf do przetworzenia
    // Zwraca:
    // - minimalny koszt cyklu Hamiltona
    static int bestfsTSP(const TSP& tsp);
};

#endif
