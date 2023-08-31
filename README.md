# Proposta do Trabalho :books:

Neste trabalho, o objetivo é criar um sistema que possibilite a funcionalidade de autocompletar e oferecer sugestões de palavras aos usuários. Para atingir essa finalidade, adotaremos aestrutura da árvore binária como base. A seguir, é apresentado os passos necessários para a implementação.

* **PASSO 1: COLETA DE DADOS** :1st_place_medal:

Ao iniciar, será solicitado ao usuário um arquivo denominado input.data, contendo uma lista de palavras. Cada palavra nesse arquivo será considerada como termo de pesquisa para o sistema.

* **PASSO 2: MODELO DE DADOS - ÁRVORES BINÁRIAS** :2nd_place_medal:

Será utilizado um conjunto de árvores binárias para construir o sistema. Essas árvores serão criadas a partir de textos previamente fornecidos (disponíveis em textos.zip). O objetivo é estabelecer uma relação entre as palavras dos textos e as palavras de pesquisa.

* **PASSO 3: SUGESTÕES DE PALAVRAS RELEVANTES** :3rd_place_medal:

Os resultados da análise serão apresentados em um arquivo chamado output.data. Esse arquivo conterá as relações entre as palavras pesquisadas e cada arquivo de texto. Além disso, a relevância de cada palavra será calculada com base em sua frequência nos textos. Para tal, utilize o trabalho recentemente realizado, o contador de palavras.

**ABORDAGEM DE IMPLEMENTAÇÃO**

A abordagem consistirá em três etapas diferentes:

  1. ```Árvore Binária Padrão```: Será implementado uma árvore binária tradicional, selecionando as palavras mais relevantes e relacionadas à pesquisa em cada texto. A relevância de uma palavra será determinada por sua frequência e proximidade palavra de pesquisa.
  2. ```Codificação de Huffman```: Será explorado o uso do código de Huffman para otimizar a árvore binária padrão. Calcularemos códigos para cada palavra e reorganizaremos a estrutura da árvore com base nesses códigos. Avaliaremos se essa abordagem oferece vantagens em relação à anterior.
  3. ```Árvore AVL```: Será implementado uma árvore AVL e repetiremos o processo de análise. Compararemos o tempo médio de processamento entre a construção da estrutura e a geração de saída em comparação com as abordagens anteriores.

# O algoritmo :computer:

# A lógica :bulb:

```Árvore Binária```

Árvores binárias são estruturas de dados fundamentais no contexto de Ciência da Computação. Em particular, Árvores Binárias de Pesquisa são aplicadas na solução de diversos problemas que demandam eficiência em operações básicas, como busca, inserção e remoção. Informalmente, uma Árvore Binária de Pesquisa (BST)1 é uma estrutura de dados de árvore binária baseada em nós, onde a subárvore à esquerda de cada nó possui valores numéricos inferiores ao nó e a subárvore à direita de cada nó possui valores numéricos superiores ao nó. Formalmente, uma BST é definida recursivamente da seguinte forma:

* A é uma árvore nula;
* A é uma tripla (Esq,raiz,Dir), onde Esq e Dir são árvores binárias de pesquisa e Esq contém apenas valores menores do que o armazenado na raiz, enquanto Dir contém apenas valores maiores do que o armazenado na raiz.

<p align="center">
<img src="image/arvoreBinaria.png" width="300"/>
</p>
<p align="center">
<em>Imagem 1: Exemplo de Árvore Binária. </em>
</p>

```Codificação de Huffman```

Uma árvore binária completa, chamada de árvore de Huffman é construída recursivamente a partir da junção dos dois símbolos de menor probabilidade, que são então somados em símbolos auxiliares e estes símbolos auxiliares recolocados no conjunto de símbolos. O processo termina quando todos os símbolos forem unidos em símbolos auxiliares, formando uma árvore binária. A árvore é então percorrida, atribuindo-se valores binários de 1 ou 0 para cada aresta, e os códigos são gerados a partir desse percurso.

<p align="center">
<img src="image/Huffman.png" width="300"/>
</p>
<p align="center">
<em>Imagem 2: Exemplo do Algoritmo de Huffman. </em>
</p>

```Árvore AVL```

Árvore AVL é uma árvore binária de busca balanceada, ou seja, uma árvore balanceada (árvore completa) são as árvores que minimizam o número de comparações efetuadas no pior caso para uma busca com chaves de probabilidades de ocorrências idênticas. Contudo, para garantir essa propriedade em aplicações dinâmicas, é preciso reconstruir a árvore para seu estado ideal a cada operação sobre seus nós (inclusão ou exclusão), para ser alcançado um custo de algoritmo com o tempo de pesquisa tendendo a O(logn).

As operações de busca, inserção e remoção de elementos possuem complexidade O(logn), no qual n é o número de elementos da árvore, que são aplicados a árvore de busca binária.

<p align="center">
<img src="image/treeAVL.png" width="300"/>
</p>
<p align="center">
<em>Imagem 3: Exemplo de uma Árvore AVL. </em>
</p>

# Conclusão :dart:

# Compilação e Execução 	:open_file_folder:

O algoritmo disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

<div>

| Comando                |  Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

</div>
