#ifndef CONFIG_LOADER_H
#define CONFIG_LOADER_H

#include <string>
#include <vector>

// Deklaracja klasy ConfigLoader
class ConfigLoader {
public:
    // Funkcja statyczna do wczytywania konfiguracji
    // Parametry:
    // - configFile: ścieżka do pliku konfiguracyjnego
    // - testFiles: wektor do przechowywania nazw plików testowych
    // - minN: minimalna wartość rozmiaru grafu
    // - numIterations: liczba iteracji testowych
    static void loadConfig(const std::string& configFile, std::vector<std::string>& testFiles, int& minN, int& numIterations);
};

#endif
