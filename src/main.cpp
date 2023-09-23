#include "frequency.hpp"
#include "treeAVL.hpp"
#include "treeBinary.hpp"
#include "treeHuffman.hpp"

int main() {
    // Redireciona a saída para um arquivo
    ofstream outputFile("src/dataset/output.txt");
    if (!outputFile) {
        cerr << "Erro ao abrir o arquivo de saída." << endl;
        return 1;
    }
    
    streambuf* coutBuf = cout.rdbuf(); // Salva o buffer padrão de cout
    cout.rdbuf(outputFile.rdbuf()); // Redireciona cout para o arquivo de saída

    int numFiles = 6; // Número de arquivos de entrada
    unordered_set<string> stopwords = readStopwords("src/dataset/stopword.txt");

    for (int i = 1; i <= numFiles; i++) {
        string filename = "src/dataset/input/input" + to_string(i) + ".txt";
        string nomeArquivo = "arquivo " + to_string(i);
        ifstream inputFile(filename);

        if (!inputFile) {
            cerr << "Erro ao abrir o arquivo " << filename << endl;
            exit(1);
        }

        cout << endl << endl;
        cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        
        cout << "INFORMAÇÕES" << endl;
        cout << endl;
        
        cout << "TEXTO UTILIZADO: " << nomeArquivo << endl;
        cout << endl;

        unordered_map<string, int> frequencyMap = processText(inputFile, stopwords);

        // Encontra as 10 principais palavras para este arquivo
        vector<WordFrequency> topWords = findTopK(frequencyMap, 10);

        int totalWords = 0;
        for (const auto &pair : frequencyMap) {
            totalWords += pair.second;
        }

        for (size_t j = 0; j < topWords.size(); ++j) {
            cout << "PALAVRAS DE MAIOR FREQUENCIA: " << topWords[j].word << endl;

            if (j < topWords.size() - 1) {
                cout << "PROXIMA PALAVRA DA ÁRVORE: " << topWords[j + 1].word << endl;
            }

            cout << "FREQUENCIA: " << topWords[j].frequency << endl;
            cout << "TOTAL DE PALAVRAS: " << totalWords << endl;

            // Declara as variáveis de raiz das árvores aqui
            TreeNode *binaryTreeRoot = nullptr;
            AVLNode *avlRoot = nullptr;
            HuffmanNode *huffmanTreeRoot = nullptr;

            // Mede o tempo de execução da árvore binária
            auto startBinary = high_resolution_clock::now(); // Inicia a contagem de tempo
            for (size_t k = 0; k <= j; ++k) {
                insertIntoBinaryTree(binaryTreeRoot, topWords[k]);
            }
            auto stopBinary = high_resolution_clock::now(); // Encerra a contagem de tempo
            auto durationBinary = duration_cast<duration<double>>(stopBinary - startBinary); // Calcula a duração em segundos

            // Mede o tempo de execução da árvore AVL
            auto startAVL = high_resolution_clock::now(); // Inicia a contagem de tempo
            for (size_t k = 0; k <= j; ++k) {
                avlRoot = insertIntoAVL(avlRoot, topWords[k].word, topWords[k].frequency);
            }
            auto stopAVL = high_resolution_clock::now(); // Encerra a contagem de tempo
            auto durationAVL = duration_cast<duration<double>>(stopAVL - startAVL); // Calcula a duração em segundos

            // Mede o tempo de execução da árvore de Huffman
            auto startHuffman = high_resolution_clock::now(); // Inicia a contagem de tempo
            vector<WordFrequency> huffmanWords(topWords.begin(), topWords.begin() + j + 1);
            huffmanTreeRoot = buildHuffmanTree(huffmanWords);
            auto stopHuffman = high_resolution_clock::now(); // Encerra a contagem de tempo
            auto durationHuffman = duration_cast<duration<double>>(stopHuffman - startHuffman); // Calcula a duração em segundos

            cout << endl;
            cout << "ÁRVORES" << endl;
            cout << endl;

            cout << "ÁRVORE BINÁRIA(PosOrdem):" << endl;
            cout << "(";
            printBinaryTreePostOrder(binaryTreeRoot);
            cout << ")" << endl;

            cout << "ÁRVORE AVL(PosOrdem):" << endl;
            cout << "(";
            printAVLTreePostOrder(avlRoot);
            cout << ")" << endl;

            cout << "ÁRVORE DE HUFFMAN(PosOrdem):" << endl;
            cout << "(";
            printHuffmanTreePostOrder(huffmanTreeRoot);
            cout << ")" << endl;

            cout << endl;
            cout << "TEMPO DE EXECUÇÃO DAS ÁRVORES" << endl;
            cout << endl;

            cout << "Tempo de execução da árvore Binária: " << fixed << durationBinary.count() * 1000 << " ms" << endl;
            cout << "Tempo de execução da árvore AVL: " << fixed << durationAVL.count() * 1000 << " ms" << endl;
            cout << "Tempo de execução da árvore Huffman: " << fixed << durationHuffman.count() * 1000 << " ms" << endl;

            cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;
        }

        inputFile.close(); // Fecha o arquivo após processá-lo
    }

    // Restaura a saída padrão
    cout.rdbuf(coutBuf);
    outputFile.close(); // Fecha o arquivo de saída

    return 0;
}
