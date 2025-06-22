 // -- Definindo um tipo que é um ponteiro para o nó --
 typedef struct NO* ArvBin;

 // --- FUNÇÕES ---
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
