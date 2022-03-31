#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char cpf[50];
char nome[100];
char sexo[15];
int idade;

struct estrutura{
	char pergunta[100];
	int pontuacao;
};

struct estrutura questoes[] = {
	{.pergunta = "Tem febre: ", .pontuacao = 5},
	{.pergunta = "Tem Dor de cabeça: ", .pontuacao = 1},
	{.pergunta = "Tem secreção nasal ou espirros: ", .pontuacao = 1},
	{.pergunta = "Tem dor/irritação na garganta: ", .pontuacao = 1},
	{.pergunta = "Tem tosse seca: ", .pontuacao = 3},
	{.pergunta = "Tem dificuldade respiratória: ", .pontuacao = 10},
	{.pergunta = "Tem dores no corpo: ", .pontuacao = 1},
	{.pergunta = "Tem diarréia: ", .pontuacao = 1},
	{.pergunta = "Esteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19: ", .pontuacao = 10},
	{.pergunta = "Esteve em locais com grande aglomeração: ", .pontuacao = 3},
};

void perguntas(){
	int cont = 0, soma = 0;
	char resp;
	
	FILE *arquivotxt;
	arquivotxt = fopen("dataBase.txt", "a");
	
	if (arquivotxt == NULL){
		printf("Erro ao criar arquivo");
	}
	
	printf("Responda as perguntas com S(sim) ou N(não).\n");
	printf("============================================\n");
	for (cont = 0; cont < 10; cont++){
		printf("%s", questoes[cont].pergunta);
		scanf("%c", &resp);
		fflush(stdin);
		fprintf(arquivotxt, "%s %c\n", questoes[cont].pergunta, resp);
		if(resp == 'S' || resp == 's'){
			soma = soma + questoes[cont].pontuacao;
		}
	}fprintf(arquivotxt, "Pontuação final do paciente: %d", soma);
	
	fclose(arquivotxt);
	
	system("cls");
	if (soma >= 0 && soma < 10){
		printf("O paciente somou %d, deve se encaminhar para ala de baixo risco.\n", soma);
	}
	if (soma >= 10 && soma < 20){
		printf("O paciente somou %d, deve se encaminhar para ala de médio risco.\n", soma);
	}
	if (soma >= 20 ){
		printf("O paciente somou %d, deve se encaminhar para ala de alto risco.\n", soma);
	}
}
void cadastrarPaciente(){
	
	FILE *arquivotxt;
	arquivotxt = fopen("dataBase.txt", "a");
	
	if (arquivotxt == NULL){
		printf("Erro ao criar arquivo");
	}
	
	printf("Digite o CPF do paciente: ");
	scanf("%s", cpf);
	fflush(stdin);
	printf("Digite o Nome do paciente: ");
	scanf("%s", nome);
	fflush(stdin);
	printf("Digite o Sexo do paciente: ");
	scanf("%s", sexo);
	fflush(stdin);
	printf("Digite o Idade do paciente: ");
	scanf("%d", &idade);
	fflush(stdin);
	
	fprintf(arquivotxt, "Nome: %s\n", nome);
	fprintf(arquivotxt, "CPF: %s\n", cpf);
	fprintf(arquivotxt, "Sexo: %s\n", sexo);
	fprintf(arquivotxt, "Idade: %d\n", idade);
	fprintf(arquivotxt, "==============================\n");
	fclose(arquivotxt);
	printf("Dados salvo!\n");
	system("pause");
	
}



int main() {
	int menu, cont;
	setlocale(LC_ALL, "Portuguese");
	
	printf("===========MENU==============\n");
	printf("1 - Cadastro\n");
	printf("2 - Sair\n");
	scanf("%d", &menu);
	fflush(stdin);
	
	if (menu == 1){
		printf("===========Cadastro==============\n");
		cadastrarPaciente();
		system("cls");
		perguntas();
		system("pause");
		printf("\n");
		system("cls");
		main();
		
	
	
	
	
	}else{
		printf("Finalizando o programa...");
	}
	
	
	
	return 0;
}
