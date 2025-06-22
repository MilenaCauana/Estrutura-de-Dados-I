/* Aqui terá:
 - Os protótipos das funções;
 - O tipo de dado armazenado na árvore;
 - O ponteiro "árvore';
 */

 // -- Definindo um tipo que é um ponteiro para o nó --
 typedef struct NO* ArvBin;

 // --- FUNÇÕES ---
 ArvBin *cria_ArvBin();

 void libera_ArvBin(ArvBin *raiz);

 int estaVazia_ArvBin(ArvBin *raiz);

 int altura_ArvBin(ArvBin *raiz);

 int totalNO_ArvBin(ArvBin *raiz);

 void preOrdem_ArvBin(ArvBin *raiz);

 void emOrdem_ArvBin(ArvBin *raiz);

 void posOrdem_ArvBin(ArvBin *raiz);
