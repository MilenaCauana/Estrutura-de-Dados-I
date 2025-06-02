//Aqui, ele irá guardar uma estrutura Aluno
typedef struct
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
}Aluno;

typedef struct hash Hash;

//---------Funções para manipular a tabela hash-------------
Hash *criaHash(int TABLE_SIZE);
void liberaHash(Hash *ha);

int valorString(char *str);

int insereHash_SemColisao(Hash  *ha, Aluno aluno);
int buscaHash_SemColisao(Hash *ha, int mat, Aluno *aluno);

int insereHash_EnderAberto(Hash *ha, Aluno aluno);
int buscaHash_EnderAberto(Hash *ha, int mat, Aluno *aluno);

