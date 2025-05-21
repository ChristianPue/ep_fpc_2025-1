// EP_Código_AraujoCanales_Christian_Pregunta_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Función para generar un gen aleatorio
string generateRandomGen() {
    const char genes[] = { 'A', 'B', 'C', 'P', 'E' };
    string gen = "";
    for (int i = 0; i < 5; i++) {
        gen += genes[rand() % 5];
    }
    return gen;
}

// Función para generar una cadena genómica aleatoria
string generateRandomChain(int length) {
    const char genes[] = { 'A', 'B', 'C', 'P', 'E' };
    string chain = "";
    for (int i = 0; i < length; i++) {
        chain += genes[rand() % 5];
    }
    return chain;
}

// Función para calcular la tabla de prefijos para el algoritmo KMP
vector<int> computePrefixFunction(const string& pattern) {
    int m = pattern.length();
    vector<int> pi(m, 0);
    int k = 0;

    for (int i = 1; i < m; i++) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = pi[k - 1];
        }
        if (pattern[k] == pattern[i]) {
            k++;
        }
        pi[i] = k;
    }

    return pi;
}

// Algoritmo KMP para encontrar todas las ocurrencias del patrón en la cadena
vector<int> KMPSearch(const string& text, const string& pattern) {
    vector<int> result;
    int n = text.length();
    int m = pattern.length();

    if (m == 0) return result;

    vector<int> pi = computePrefixFunction(pattern);
    int q = 0;

    for (int i = 0; i < n; i++) {
        while (q > 0 && pattern[q] != text[i]) {
            q = pi[q - 1];
        }
        if (pattern[q] == text[i]) {
            q++;
        }
        if (q == m) {
            result.push_back(i - m + 1);
            q = pi[q - 1];
        }
    }

    return result;
}

// Función para reemplazar las apariciones del patrón en la cadena con "ZXZXZ"
string replacePattern(const string& text, const vector<int>& positions, int patternLength) {
    string result = text;
    string replacement = "ZXZXZ";

    // Comenzamos desde la última posición para no afectar los índices
    for (int i = positions.size() - 1; i >= 0; i--) {
        result.replace(positions[i], patternLength, replacement);
    }

    return result;
}

// Función para eliminar las apariciones del patrón de la cadena
string removePattern(const string& text, const vector<int>& positions, int patternLength) {
    string result = text;

    for (int i = positions.size() - 1; i >= 0; i--) {
        result.erase(positions[i], patternLength);
    }

    return result;
}

int main() {
    srand(time(nullptr));

    cout << "Ingresar número de simulaciones:" << endl;
    int Q;
    cin >> Q;

    if (Q <= 0 || Q >= 500) {
        cout << "El número de simulaciones debe ser entre 1 y 499." << endl;
        return 1;
    }

    int maxPatternCount = 0;
    int simulationWithMaxPatterns = 0;

    for (int sim = 1; sim <= Q; sim++) {
        cout << "Ingresar cantidad de elementos en la cadena:" << endl;
        int C;
        cin >> C;

        if (C <= 20 || C >= 10000) {
            cout << "La cantidad de elementos debe ser entre 21 y 9999." << endl;
            continue;
        }

        string pattern = generateRandomGen();
        cout << "Gen SLI: " << pattern << endl;

        string chain = generateRandomChain(C);
        cout << "Cadena: " << chain << endl;

        vector<int> positions = KMPSearch(chain, pattern);

        for (size_t i = 0; i < positions.size(); i++) {
            cout << "índice: " << positions[i] << endl;
        }

        cout << "Cantidad de apariciones: " << positions.size() << endl;

        string modifiedChain = replacePattern(chain, positions, pattern.length());
        cout << "Cadena: " << modifiedChain << endl;

        if (positions.size() > maxPatternCount) {
            maxPatternCount = positions.size();
            simulationWithMaxPatterns = sim;
        }

        if (positions.size() >= 4) {
            cout << "\"Se encontraron varias veces…Genial\"" << endl;
            string cleanedChain = removePattern(chain, positions, pattern.length());
            cout << "Cadena: " << cleanedChain << endl;
        }

        cout << "************************************************************" << endl;
    }

    cout << "En la simulación **" << simulationWithMaxPatterns << "** se encontraron más patrones." << endl;

    return 0;
}