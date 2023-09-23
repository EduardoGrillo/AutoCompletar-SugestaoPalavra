#include "treeBinary.cpp"

// Função para inserir uma palavra na árvore binária, excluindo palavras de menor frequência
void insertIntoBinaryTree(TreeNode *&root, const WordFrequency &wordFrequency) {
    if (!root) {
        root = new TreeNode(wordFrequency.word, wordFrequency.frequency);
        return;
    }

    if (wordFrequency.frequency < root->frequency) {
        insertIntoBinaryTree(root->left, wordFrequency);
    } else {
        insertIntoBinaryTree(root->right, wordFrequency);
    }
}

// Função para imprimir a árvore binária em pós-ordem
void printBinaryTreePostOrder(TreeNode *root) {
    if (!root) {
        return;
    }

    printBinaryTreePostOrder(root->left);
    printBinaryTreePostOrder(root->right);
    cout << " (" << root->word << ":" << root->frequency << ") ";
}
