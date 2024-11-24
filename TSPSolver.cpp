#include "TSPSolver.h"

// Algorytm BFS (Breadth-First Search) dla problemu TSP
int TSPSolver::bfsTSP(const TSP& tsp) {
    int n = tsp.numCities; // Liczba miast
    Queue<std::pair<int, std::vector<int>>> q; // Kolejka do przechowywania stanów (koszt, trasa)
    q.push({0, {0}}); // Dodaj stan początkowy: koszt 0, trasa zaczynająca się od miasta 0
    int minCost = INT_MAX; // Minimalny koszt cyklu Hamiltona

    while (!q.empty()) {
        auto [currentCost, path] = q.front();
        q.pop();

        // Sprawdź, czy odwiedzono wszystkie miasta
        if (path.size() == n) {
            currentCost += tsp.graph[path.back()][path[0]]; // Dodaj koszt powrotu do miasta startowego
            minCost = std::min(minCost, currentCost); // Aktualizuj minimalny koszt
            continue;
        }

        int lastCity = path.back(); // Ostatnie odwiedzone miasto
        for (int i = 0; i < n; ++i) {
            // Jeśli miasto i nie zostało jeszcze odwiedzone
            if (std::find(path.begin(), path.end(), i) == path.end()) {
                int newCost = currentCost + tsp.graph[lastCity][i]; // Dodaj koszt przejścia do miasta i
                auto newPath = path; // Skopiuj obecną trasę
                newPath.push_back(i); // Dodaj miasto i do trasy
                q.push({newCost, newPath}); // Dodaj nowy stan do kolejki
            }
        }
    }

    return minCost; // Zwróć minimalny koszt cyklu Hamiltona
}

// Algorytm DFS (Depth-First Search) dla problemu TSP
int TSPSolver::dfsTSP(const TSP& tsp) {
    int n = tsp.numCities; // Liczba miast
    Stack<std::pair<int, std::vector<int>>> s; // Stos do przechowywania stanów (koszt, trasa)
    s.push({0, {0}}); // Dodaj stan początkowy: koszt 0, trasa zaczynająca się od miasta 0
    int minCost = INT_MAX; // Minimalny koszt cyklu Hamiltona

    while (!s.empty()) {
        auto [currentCost, path] = s.top();
        s.pop();

        // Sprawdź, czy odwiedzono wszystkie miasta
        if (path.size() == n) {
            currentCost += tsp.graph[path.back()][path[0]]; // Dodaj koszt powrotu do miasta startowego
            minCost = std::min(minCost, currentCost); // Aktualizuj minimalny koszt
            continue;
        }

        int lastCity = path.back(); // Ostatnie odwiedzone miasto
        for (int i = 0; i < n; ++i) {
            // Jeśli miasto i nie zostało jeszcze odwiedzone
            if (std::find(path.begin(), path.end(), i) == path.end()) {
                int newCost = currentCost + tsp.graph[lastCity][i]; // Dodaj koszt przejścia do miasta i
                auto newPath = path; // Skopiuj obecną trasę
                newPath.push_back(i); // Dodaj miasto i do trasy
                s.push({newCost, newPath}); // Dodaj nowy stan do stosu
            }
        }
    }

    return minCost; // Zwróć minimalny koszt cyklu Hamiltona
}

// Algorytm BestFS (Best-First Search) dla problemu TSP
int TSPSolver::bestfsTSP(const TSP& tsp) {
    int n = tsp.numCities; // Liczba miast
    using Node = std::tuple<int, int, std::vector<int>>; // Typ węzła: (koszt, liczba odwiedzonych miast, trasa)
    PriorityQueue<Node, std::greater<>> pq; // Kolejka priorytetowa dla węzłów
    pq.push({0, 1, {0}}); // Dodaj stan początkowy: koszt 0, 1 odwiedzone miasto, trasa zaczynająca się od miasta 0
    int minCost = INT_MAX; // Minimalny koszt cyklu Hamiltona

    while (!pq.empty()) {
        auto [currentCost, visitedCount, path] = pq.top();
        pq.pop();

        // Sprawdź, czy odwiedzono wszystkie miasta
        if (visitedCount == n) {
            currentCost += tsp.graph[path.back()][path[0]]; // Dodaj koszt powrotu do miasta startowego
            minCost = std::min(minCost, currentCost); // Aktualizuj minimalny koszt
            continue;
        }

        int lastCity = path.back(); // Ostatnie odwiedzone miasto
        for (int i = 0; i < n; ++i) {
            // Jeśli miasto i nie zostało jeszcze odwiedzone
            if (std::find(path.begin(), path.end(), i) == path.end()) {
                int newCost = currentCost + tsp.graph[lastCity][i]; // Dodaj koszt przejścia do miasta i
                auto newPath = path; // Skopiuj obecną trasę
                newPath.push_back(i); // Dodaj miasto i do trasy
                pq.push({newCost, visitedCount + 1, newPath}); // Dodaj nowy stan do kolejki priorytetowej
            }
        }
    }

    return minCost; // Zwróć minimalny koszt cyklu Hamiltona
}
