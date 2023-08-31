# Proposta do Trabalho

Neste trabalho, o objetivo é criar um sistema que possibilite a funcionalidade de autocompletar e oferecer sugestões de palavras aos usuários. Para atingir essa finalidade, adotaremos aestrutura da árvore binária como base. A seguir, é apresentado os passos necessários para a implementação.

* **PASSO 1: COLETA DE DADOS**

Ao iniciar, será solicitado ao usuário um arquivo denominado input.data, contendo uma lista de palavras. Cada palavra nesse arquivo será considerada como termo de pesquisa para o sistema.

* **PASSO 2: MODELO DE DADOS - ÁRVORES BINÁRIAS**

Será utilizado um conjunto de árvores binárias para construir o sistema. Essas árvores serão criadas a partir de textos previamente fornecidos (disponíveis em textos.zip). O objetivo é estabelecer uma relação entre as palavras dos textos e as palavras de pesquisa.

* **PASSO 3: SUGESTÕES DE PALAVRAS RELEVANTES**

Os resultados da análise serão apresentados em um arquivo chamado output.data. Esse arquivo conterá as relações entre as palavras pesquisadas e cada arquivo de texto. Além disso, a relevância de cada palavra será calculada com base em sua frequência nos textos. Para tal, utilize o trabalho recentemente realizado, o contador de palavras.

**ABORDAGEM DE IMPLEMENTAÇÃO**

A abordagem consistirá em três etapas diferentes:

  1. ```Árvore Binária Padrão```: Será implementado uma árvore binária tradicional, selecionando as palavras mais relevantes e relacionadas à pesquisa em cada texto. A relevância de uma palavra será determinada por sua frequência e proximidade palavra de pesquisa.
  2. ```Codificação de Huffman```: Será explorado o uso do código de Huffman para otimizar a árvore binária padrão. Calcularemos códigos para cada palavra e reorganizaremos a estrutura da árvore com base nesses códigos. Avaliaremos se essa abordagem oferece vantagens em relação à anterior.
  3. ```Árvore AVL```: Será implementado uma árvore AVL e repetiremos o processo de análise. Compararemos o tempo médio de processamento entre a construção da estrutura e a geração de saída em comparação com as abordagens anteriores.

# A lógica 

```Árvore Binária```

<p align="center">
<img src="image/arvoreBinaria.png" width="300"/>
</p>
<p align="center">
<em>Imagem 1: Exemplo de Árvore Binária. </em>
</p>

```Codificação de Huffman```

<p align="center">
<img src="image/Huffman.png" width="300"/>
</p>
<p align="center">
<em>Imagem 2: Exemplo do Algoritmo de Huffman. </em>
</p>

```Árvore AVL```

<p align="center">
<img src="image/treeAVL" width="300"/>
</p>
<p align="center">
<em>Imagem 3: Exemplo de uma Árvore AVL. </em>
</p>


# O algoritmo 

# Conclusão

# Compilação e Execução

O algoritmo disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:

<div>

| Comando                |  Função                                                                                           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

</div>
