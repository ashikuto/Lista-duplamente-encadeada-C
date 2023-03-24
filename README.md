# Lista-duplamente-encadeada-C

Este código implementa uma lista duplamente encadeada, onde cada elemento possui três campos: número de matrícula (int), nome (string de até 80 caracteres) e média (float). Além disso, também é possível realizar operações de inserção no início e no final da lista, remoção de um elemento, impressão da lista completa, busca de um elemento específico, verificação se a lista está vazia e separação da lista em duas a partir de um elemento específico.

A estrutura da lista é definida pela struct "lista", que possui um ponteiro para o próximo elemento e outro para o elemento anterior. Ainda na parte superior do código, há a definição de um tipo "Lista" que é um ponteiro para uma struct "lista".

As funções implementadas são:

vazia: recebe um ponteiro para a lista e retorna true se a lista estiver vazia ou false caso contrário.
inserirComeco: recebe um ponteiro para a lista, o número de matrícula, o nome e a média do elemento a ser inserido e insere esse elemento no início da lista. Retorna um ponteiro para o novo início da lista.
imprimir: recebe um ponteiro para a lista e imprime todos os elementos da lista.
buscar: recebe um ponteiro para a lista e um valor de matrícula. Retorna um ponteiro para o elemento da lista que possui a matrícula buscada ou NULL caso contrário.
remover: recebe um ponteiro para a lista e um valor de matrícula. Remove o elemento da lista que possui a matrícula buscada e retorna um ponteiro para o início da lista atualizado.
inserirFinalDaLista: recebe um ponteiro para a lista, o número de matrícula, o nome e a média do elemento a ser inserido e insere esse elemento no fim da lista. Retorna um ponteiro para o novo início da lista.
separarLista: recebe um ponteiro para a lista e um valor de matrícula. Separa a lista em duas a partir do elemento que possui a matrícula buscada. Retorna um ponteiro para a nova lista criada a partir do elemento buscado.
Na função main, há um menu de opções que permite realizar todas as operações possíveis com a lista.
