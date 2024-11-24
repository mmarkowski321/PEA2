#include "ConfigLoader.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

void ConfigLoader::loadConfig(const std::string& configFile, std::vector<std::string>& testFiles, int& minN, int& numIterations) {
    // Otwieranie pliku konfiguracyjnego
    std::ifstream file(configFile);
    if (!file.is_open()) {
        // Jeśli nie uda się otworzyć pliku, wypisz komunikat i zakończ program
        std::cerr << "Cannot open configuration file: " << configFile << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;

    // Wczytywanie nazw plików testowych (oczekiwane trzy linie)
    for (int i = 0; i < 3; ++i) {
        if (std::getline(file, line)) {
            // Dodaj nazwę pliku do listy plików testowych
            testFiles.push_back(line);
        } else {
            // Jeśli brak wystarczającej liczby linii, zgłoś błąd i zakończ program
            std::cerr << "Insufficient data in the configuration file!" << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }

    // Wczytywanie minimalnej wartości N
    if (std::getline(file, line)) {
        try {
            // Konwersja ciągu znaków na liczbę
            minN = std::stoi(line);
        } catch (const std::invalid_argument& e) {
            // Obsługa błędu: jeśli konwersja nie jest możliwa
            std::cerr << "Invalid value for minimum N in the configuration file!" << std::endl;
            std::exit(EXIT_FAILURE);
        }
    } else {
        // Jeśli brak wartości dla N, zgłoś błąd i zakończ program
        std::cerr << "No value provided for minimum N in the configuration file!" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    // Wczytywanie liczby iteracji
    if (std::getline(file, line)) {
        try {
            // Konwersja ciągu znaków na liczbę
            numIterations = std::stoi(line);
        } catch (const std::invalid_argument& e) {
            // Obsługa błędu: jeśli konwersja nie jest możliwa
            std::cerr << "Invalid value for the number of iterations in the configuration file!" << std::endl;
            std::exit(EXIT_FAILURE);
        }
    } else {
        // Jeśli brak wartości dla liczby iteracji, zgłoś błąd i zakończ program
        std::cerr << "No value provided for the number of iterations in the configuration file!" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    // Zamknięcie pliku
    file.close();
    // Wyświetlenie informacji o pomyślnym wczytaniu pliku
    std::cout << "Successfully loaded " << configFile << std::endl;
}
