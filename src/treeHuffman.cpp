#ifndef TREEHUFFMAN_HPP
#define TREEHUFFMAN_HPP

#include "frequency.cpp"

struct HuffmanNode {
    string word;
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(string w, int freq) : word(w), frequency(freq), left(nullptr), right(nullptr) {}
};

// Função para comparar os nós da árvore de Huffman com base em suas frequências
struct CompareHuffmanNode {
    bool operator()(const HuffmanNode *node1, const HuffmanNode *node2) const {
        return node1->frequency > node2->frequency;
    }
};

#endif