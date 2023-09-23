#include "treeAVL.cpp"

AVLNode *avlRoot = nullptr;

// implementação de funções para calcular a altura de um nó e calcular o fator de equilíbrio
int getHeight(AVLNode *node) {
    if (!node) return 0;
    return node->height;
}

int getBalanceFactor(AVLNode *node) {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Função para realizar rotação simples à direita na árvore AVL
AVLNode *rotateRight(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Função para realizar rotação simples à esquerda na árvore AVL
AVLNode *rotateLeft(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Função para realizar rotação dupla à direita (esquerda-direita) na árvore AVL
AVLNode *rotateLeftRight(AVLNode *root) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
}

// Função para realizar rotação dupla à esquerda (direita-esquerda) na árvore AVL
AVLNode *rotateRightLeft(AVLNode *root) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
}

// Função para inserir uma palavra na árvore AVL
AVLNode *insertIntoAVL(AVLNode *root, string word, int frequency) {
    if (!root) return new AVLNode(word, frequency);

    if (word < root->word) {
        root->left = insertIntoAVL(root->left, word, frequency);
    } else if (word > root->word) {
        root->right = insertIntoAVL(root->right, word, frequency);
    } else {
        // A palavra já existe, apenas atualize a frequência
        root->frequency += frequency;
    }

    // Atualize a altura do nó
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Calcule o fator de equilíbrio do nó
    int balanceFactor = getBalanceFactor(root);

    // Verifique e realize as rotações necessárias para manter o equilíbrio
    if (balanceFactor > 1) {
        if (word < root->left->word) {
            return rotateRight(root);
        } else {
            return rotateLeftRight(root);
        }
    }
    if (balanceFactor < -1) {
        if (word > root->right->word) {
            return rotateLeft(root);
        } else {
            return rotateRightLeft(root);
        }
    }

    return root;
}

// Função para imprimir a árvore AVL em pós-ordem
void printAVLTreePostOrder(AVLNode *root) {
    if (!root) return;

    printAVLTreePostOrder(root->left);
    printAVLTreePostOrder(root->right);
    cout << " (" << root->word << ":" << root->frequency << ") ";
}