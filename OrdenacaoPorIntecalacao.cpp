  
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};

/* MergeSort criado usando como base os algoritmos presentes nos seguintes links:
https://www.programiz.com/dsa/merge-sort
https://www.geeksforgeeks.org/merge-sort/
*/

void merge (Endereco [] e, int inicio, int meio, int fim)
{
    int x = meio - inicio + 1;
    int y = fim - meio;

    int esq[x], dir[y];
    for (int i = 0; i <x; i++)
    {
        esq[i] = e[inicio + i];
    }
    for (int i = 0; i <y; i++)
    {
        dir[i] = e[meio + 1 + i];
    }

    int a, b, c;
    a = 0;
    b = 0;
    c = inicio;

    while(a < x && b < y)
    {
        if(esq[a] < dir[b])
        {
            e[c] = esq[a];
            a++;
        }
        else
        {
            e[c] = dir[b];
            b++;
        }
        c++;
    }

    while(a < x)
    {
        e[c] = esq[a];
        a++;
        c++;
    }

    while(b < y)
    {
        e[c] = dir[b];
        b++;
        c++;
    }

}

void mergeSort(Endereco [] e, int inicio, int fim)
{
    if(fim > 1)
    {
        return;
    }
    else
    {
        int meio = 1 + (fim - 1)/2;

        mergeSort(e, 1, meio);
        merqueSort(e, meio+1, fim);

        merge(e, inicio, meio, fim);
    }
}

int main(int argc, char** argv)
{
    FILE *f;

    /*if(argc != 2)
	{
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
    }
    */
    f = fopen("cep.dat","r");
    fseek(f,0,SEEK_END);
	long tamanhoArquivo = ftell(f);
	rewind(f);

    long indiceEndereco = tamanhoArquivo/sizeof(Endereco);

    Endereco [indiceEndereco + 1] e;

    long inicio = 0;
    long fim = indicEndereco;

    for(i = 0; i < fim; i++)
    {
        fseek(f, i, SEEK_SET);
        fread(&e, sizeof(Endereco), 1, f);
    }
    fclose(f);

    mergeSort(e, inicio, fim);

    for(i = 0; i < fim; i++)
    {
        printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",e[i].logradouro,e[i].bairro,e[i].cidade,e[i].uf,e[i].sigla,e[i].cep);
    }
}