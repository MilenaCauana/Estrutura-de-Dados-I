/* Aqui ter�:
 - Os prot�tipos das fun��es;
 - O tipo de dado armazenado na �rvore;
 - O ponteiro "�rvore';
 */

 // -- Definindo um tipo que � um ponteiro para o n� --
 typedef struct NO* ArvBin;

 // --- FUN��ES ---
 ArvBin *cria_ArvBin();

 void libera_ArvBin(ArvBin *raiz);

 int estaVazia_ArvBin(ArvBin *raiz);

 int altura_ArvBin(ArvBin *raiz);

 int totalNO_ArvBin(ArvBin *raiz);

 void preOrdem_ArvBin(ArvBin *raiz);

 void emOrdem_ArvBin(ArvBin *raiz);

 void posOrdem_ArvBin(ArvBin *raiz);
