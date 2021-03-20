#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Código desevolvido usando como base os códigos fornecidos em aula pelo professor Renato
//e com o auxílio do aluno Leandro Zirondi

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

void buscaBinaria();

int main(int argc, char** argv)
{
    FILE *f;

    if(argc != 2)
	{
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
    }

    f = fopen("cep_ordenado.dat","r");
	fseek(f,0,SEEK_END);
	long tamanhoArquivo = ftell(f);
	rewind(f); // fseek(f,0,SEEK_SET);

    buscaBinaria (f, 0, (tamanhoArquivo/sizeof(Endereco))-1, agrv[1]);

}

void buscaBinaria (FILE* file, long inicio, long fim, char cep[8])
{
    long meio;
    long pivo;
    Endereco e;

    while(inicio<=fim)
	{
        meio = (inicio+fim)/2;
        pivo = meio * sizeof(Endereco);
        fseek(f, pivo, SEEK_SET);
        fread(&e, sizeof(Endereco), 1, f);

		if (strNcmp(e.cep,f[meio].cep, 8) == 0)
		{
			printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",e.logradouro,e.bairro,e.cidade,e.uf,e.sigla,e.cep);
			break;
		}

		else if (strNcmp(e.cep,f[meio].cep, 8) < 0)
		{
			fim = meio - 1;
		}

			else if (strNcmp(e.cep,f[meio].cep, 8) > 0)
		{
			inicio = meio + 1;
		}
	}
}