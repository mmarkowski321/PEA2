#include "ConfigLoader.h"
#include "Tester.h"

int main() {
    // Ścieżka do pliku konfiguracyjnego
    std::string configFile = "config.txt";

    // Wektor przechowujący nazwy plików testowych
    std::vector<std::string> testFiles;

    // Minimalny rozmiar grafu oraz liczba iteracji testowych
    int minN = 0;
    int numIterations = 0;

    // Wczytywanie konfiguracji z pliku
    // Funkcja wypełni testFiles, minN oraz numIterations na podstawie zawartości config.txt
    ConfigLoader::loadConfig(configFile, testFiles, minN, numIterations);

    // Tworzenie obiektu Tester do przeprowadzania testów
    Tester tester;

    // Testowanie poprawności na podstawie danych z plików testowych
    tester.testCorrectnessFromFiles(testFiles);

    // Testowanie dla różnych rozmiarów grafów i liczby iteracji
    tester.testForDifferentNFromConfig(minN, numIterations);

    // Zwracanie kodu zakończenia 0 (sukces)
    return 0;
}
