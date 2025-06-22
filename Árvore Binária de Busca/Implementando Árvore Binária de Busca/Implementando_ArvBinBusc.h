 // -- Definindo um tipo que � um ponteiro para o n� --
 typedef struct NO* ArvBin;

 // --- FUN��ES ---
 ArvBin *cria_ArvBinBusc();

 void libera_ArvBinBusc(ArvBin *raiz);

 int estaVazia_ArvBinBusc(ArvBin *raiz);

 int altura_ArvBinBusc(ArvBin *raiz);

 int totalNO_ArvBinBusc(ArvBin *raiz);

 void preOrdem_ArvBinBusc(ArvBin *raiz);

 void emOrdem_ArvBinBusc(ArvBin *raiz);

 void posOrdem_ArvBinBusc(ArvBin *raiz);

 int remove_ArvBinBusc(ArvBin *raiz, int valor);

 int insere_ArvBinBusc (ArvBin *raiz, int valor);

 int consulta_ArvBinBusc (ArvBin *raiz, int valor);

 struct NO* remove_atual(struct NO* atual);
