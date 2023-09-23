#ifndef TREEAVL_HPP
#define TREEAVL_HPP

#include "frequency.cpp"

struct AVLNode {
    string word;
    int frequency;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(string w, int f) : word(w), frequency(f), left(nullptr), right(nullptr), height(1) {}
};

#endif