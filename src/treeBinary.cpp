#ifndef TREEBINARY_HPP
#define TREEBINARY_HPP

#include "frequency.cpp"

// Definir a estrutura de nó para a árvore binária
struct TreeNode {
    string word;
    int frequency;
    TreeNode *left;
    TreeNode *right;

    TreeNode(string w, int f) : word(w), frequency(f), left(nullptr), right(nullptr) {}
};

#endif