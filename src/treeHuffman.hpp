#include "treeHuffman.cpp"

// Função para construir a árvore de Huffman
HuffmanNode *buildHuffmanTree(vector<WordFrequency> &words) {
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareHuffmanNode> minHeap;

    // Cria um nó para cada palavra e frequência e insira-o na fila de prioridade
    for (const auto &word : words) {
        HuffmanNode *node = new HuffmanNode(word.word, word.frequency);
        minHeap.push(node);
    }

    // Constroi a árvore de Huffman combinando os nós com menores frequências
    while (minHeap.size() > 1) {
        HuffmanNode *left = minHeap.top();
        minHeap.pop();
        HuffmanNode *right = minHeap.top();
        minHeap.pop();

        HuffmanNode *parent = new HuffmanNode("", left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        minHeap.push(parent);
    }

    // O nó raiz da árvore de Huffman é o último nó na fila de prioridade
    return minHeap.top();
}

// Função para imprimir a árvore de Huffman em pós-ordem com frequências em binário
void printHuffmanTreePostOrder(HuffmanNode* root) {
    if (!root) return;

    printHuffmanTreePostOrder(root->left);
    printHuffmanTreePostOrder(root->right);

    if (!root->left && !root->right) {
        // Converte a frequência em binário com 8 dígitos
        string binaryFrequency;
        int frequency = root->frequency;
        for (int i = 7; i >= 0; i--) {
            int bit = (frequency >> i) & 1;
            binaryFrequency += to_string(bit);
        }
        cout << "(" << root->word << ": " << binaryFrequency << ") ";
    }
}
