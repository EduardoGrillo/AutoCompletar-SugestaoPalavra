#ifndef FREQUENCY_HPP
#define FREQUENCY_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <queue>
#include <iomanip> // Para setw
#include <chrono>  // Para medir o tempo de execução

using namespace std;
using namespace chrono;

// Define a estrutura para representar palavras e frequências.
struct WordFrequency {
    string word;
    int frequency;

    unordered_set<string> readStopwords(const string& filename);
    unordered_map<string, int> processText(ifstream& inputFile, const unordered_set<string>& stopwords);
    vector<WordFrequency> findTopK(const unordered_map<string, int>& frequencyMap, int k);

};


#endif
