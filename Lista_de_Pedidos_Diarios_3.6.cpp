/*
	Name: Lista de Pedidos diarios.cpp
	Author: João Marcos Tomaz dos Santos 
	Date: 12/04/18 17:42
	Description: Uma lista linear ordenada que grava, exclui e busca pedidos em sequencia diariamente e grava em um arquivo .txt e valida CPFs.
xyz*/

#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<windows.h>
#include <stdlib.h>

#define max 40
#define CONVERSOR 48

//Variaveis globais
char cpfGlobal[11];

//Prototipação das funções
int validaCPF2(int,int,int,int,int,int,int,int,int,int,int);

typedef struct
{
	char* nomeDono;
	char* nomeAnimal;
	int total;
	char cpf[11];//Dígitos do CPF(d1,d2,d3,d4,d5,d6,d7,d8,d9) e os Dígitos Verificadores do CPF(dv1,dv2)
	char* servico;
	char* telefone;
	int buscar;//é uma flag, sendo que 1 é para "buscar", e 0 para "não buscar"
	int codigo;
	int horario;
	
}AGENDAMENTO;

typedef struct
{
	AGENDAMENTO lista[max];
	int numAgendamentos;
}LISTA;

int validaCPF(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,int v1,int v2)
{
	int x1,x2,x3,x4,x5,x6,x7,x8,x9;//Variáveis na qual o valor do número do CPF estará multiplicado já
	int total;//Soma dos primeiros 9 dígitos
	int resto;//Resto da divisão do total por 11
	int resto1;//Resultado de 11 menos o resto
	x1=a1*10;
	x2=a2*9;
	x3=a3*8;
	x4=a4*7;
	x5=a5*6;
	x6=a6*5;
	x7=a7*4;
	x8=a8*3;
	x9=a9*2;
	total=x1+x2+x3+x4+x5+x6+x7+x8+x9;
	resto=total%11;
	if(resto<2)
	{
		if(v1==0)
		{
			if((validaCPF2(a1,a2,a3,a4,a5,a6,a7,a8,a9,v1,v2))==0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		resto1=11-resto;
		if(resto1==v1)
		{
			if((validaCPF2(a1,a2,a3,a4,a5,a6,a7,a8,a9,v1,v2))==0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 0;
		}
	}
}

int validaCPF2(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,int v1,int v2)
{
	int x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;//Variáveis na qual o valor do número do CPF estará multiplicado já
	int total;//Soma dos primeiros 10 digitos
	int resto;//Resto da divisão do total por 11
	int resto1;//Resultado de 11 menos o resto
	x1=a1*11;
	x2=a2*10;
	x3=a3*9;
	x4=a4*8;
	x5=a5*7;
	x6=a6*6;
	x7=a7*5;
	x8=a8*4;
	x9=a9*3;
	x10=v1*2;
	total=x1+x2+x3+x4+x5+x6+x7+x8+x9+x10;
	resto=total%11;
	if(resto<2)
		{
			if(v2==0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	else
		{
		resto1=11-resto;
		if(resto1==v2)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
}

void iniciarLista(LISTA* lista)
{
	lista->numAgendamentos=0;
}

void limpaTela()
{
	system("pause");
	system("cls");
}

char* inserirCpf()
{
	int cpfInt[11], flag=0;
	char cpfChar;
	AGENDAMENTO a;
	
	printf("CPF: ");
	fflush(stdin);
	gets (cpfGlobal);
	
	//conversao cpf char para vetor de int
	for(int i=0; i<11; i++)
	{
		cpfInt[i] = cpfGlobal[i] - CONVERSOR;
	}
	
	//função validaCPF retorna 0=falso 1=verdadeiro
	flag = validaCPF(cpfInt[0],cpfInt[1],cpfInt[2],cpfInt[3],cpfInt[4],cpfInt[5],cpfInt[6],cpfInt[7],cpfInt[8],cpfInt[9],cpfInt[10]);
	if(flag == 1)
	{
		puts("Cpf válido\n");
		
		return cpfGlobal;
	}
		
	else
	{
		puts("Cpf inválido!\n");
		cpfGlobal[0]='y';//esse "y"significa que o cpf é inválido
		return cpfGlobal;
	}	
}

bool inserirAgendamento(LISTA *agenda)
{
	int i = 0;
	
	if (agenda->numAgendamentos>=max)
	{
		puts("\nAgenda cheia!\nImpossível agendar!");
		return false;
	}
	
	//criação do agendamento
	AGENDAMENTO agendamento;
	char* cpff;//variavel para guardar o retorno da função inserirCpf
	char buscar;//Variavel usada para receber o valor em char da variavel buscar original que é int
	char cpfChar[11];
	int flagDoWhile=0; // flag usada para sair do Do{ }While(Teste), sendo 1 = valor correto e 0 = calor incorreto
	
	//inserção dos dados
	puts("++ == Inserir Novo Agendamento: == ++\n");
	printf("Nome do Dono: ");
	fflush(stdin);
	scanf(" %s",&agendamento.nomeDono);
	printf("Nome do Animal: ");
	fflush(stdin);
	scanf(" %s",&agendamento.nomeAnimal);
	printf("Serviço: ");
	fflush(stdin);
	scanf(" %s",&agendamento.servico);
	
	agendamento.codigo = (agenda->numAgendamentos * 1000) + 10000;
	
	do //Buscar
	{
		flagDoWhile=0;
		
		printf("Buscar(S/N): ");
		fflush(stdin);
		scanf(" %c",&buscar);
		
		if(buscar == 'N' || buscar == 'n')
		{
			agendamento.buscar=0;
			flagDoWhile=1;
		}
		
		else if(buscar == 'S' || buscar == 's')
		{
			agendamento.buscar=1;
			flagDoWhile=1;
		}
		
		else
		{
			puts("Entre apenas com S ou N, (Sim ou Não)");
			flagDoWhile=2;
		}
	}while(flagDoWhile>1);
	
	do //Horário
	{
		printf("Horário (digite apenas a hora exata!): ");
		scanf("%d",&agendamento.horario);
		
		if(agendamento.horario>24 || agendamento.horario<0)
		{
			puts("Horário inválido!");
		}
		
	}while(agendamento.horario>24 || agendamento.horario<0);
	
	do //Inserir CPF
	{
		cpff = inserirCpf();
		
		for(int i=0; i<11; i++)
		{
			cpfChar[i] = cpfGlobal[i];
		}
		
		if(cpfGlobal[0] == 'y')
		{
			printf("Verifique o CPF digitado!\n");
		}
		
		for(int i=0; i<11; i++)
		{
			agendamento.cpf[i]=cpfChar[i];
		}
			
	}while(cpfGlobal[0] == 'y');
		
	//Inserção propriamente dita
	i=agenda->numAgendamentos;
	
	while(i>0 && agenda->lista[i-1].horario > agendamento.horario)//Só abre o espaço na lista
	{
		agenda->lista[i] = agenda->lista[i-1];
		i--;
	}
	agenda->lista[i] = agendamento;
	agenda->numAgendamentos++;
	
	puts("Cliente Agendado!");
	limpaTela();
	
	return true;
}

int buscarAgendamento(LISTA *agenda, int hora)
{
	int i=0;
	
	while(i < agenda->numAgendamentos)
	{
		if(agenda->lista[i].horario == hora)
		{
			fflush(stdin);
			printf("Horário:        %d\n", agenda->lista[i].horario);
			printf("Código:         %d\n", agenda->lista[i].codigo);
			printf("Nome:           %s\n",&agenda->lista[i].nomeDono);
			printf("Nome do Animal: %s\n",&agenda->lista[i].nomeAnimal);
			printf("CPF:            %s\n", agenda->lista[i].cpf);
			printf("Serviço:        %s\n",&agenda->lista[i].servico);
			printf("Buscar          %s\n", agenda->lista[i].buscar == 0 ?"Não\n" : "Sim\n");
			
			return i;
		}
		i++;
	}
	
	printf("Nenhum agendamento para às %d horas. Horário disponível!\n", hora);
	return -1;
}

bool excluirAgendamentos(LISTA *agenda, int hora)
{
	int i, pos;
	
	pos = buscarAgendamento(agenda, hora);
	
	if(pos == -1)
		return false;
	
	i = pos;
	
	while(i < agenda->numAgendamentos)
	{
		agenda->lista[i] = agenda->lista[i+1];
		i++;
	}
	
	agenda->numAgendamentos--;
	
	puts("Agendamento Finalizado!");
	return true;
}

bool alterarAgendamento(LISTA *agenda)
{
	int h, pos, i;
	int op;
	AGENDAMENTO agendamento;
	puts(  "Hora  Nome");
	for(int i=0; i< agenda->numAgendamentos; i++)
	{
		printf(" %d    %s \n", agenda->lista[i].horario, &agenda->lista[i].nomeDono);
	}
	
	printf("\nInfome o horário para alterar os dados do agendamento: ");
	scanf("%d", &h);
	pos = buscarAgendamento(agenda, h);
	
	if(pos == -1)
	{
		puts("Nao foi encontrado!");
		return false;
	}
	
	puts("O que alterar?");
	puts("Nome do Dono     (1)");
	puts("Nome do Animal   (2)");
	puts("Horário          (3)");
	puts("Serviço          (4)");
	puts("Buscar           (5)");
	
	printf("\nEscolha: ");
	scanf(" %d", &op);
	
	switch (op)
	{
		case 1:
			puts("Informe o novo nome do dono: ");
			fflush(stdin);
			scanf("%s", &agenda->lista[pos].nomeDono);
			break;
		
		case 2:
			puts("Informe o novo nome do animal: ");
			fflush(stdin);
			scanf("%s", &agendamento.nomeAnimal);
			break;
			
		case 3:
			puts("Informe o novo horário: ");
			fflush(stdin);
			scanf("%d", &agendamento.horario);
			//ordenar(agenda, agenda->lista[pos].horario);
			
			i = pos;
			while(i>0 && agenda->lista[i-1].horario > agendamento.horario)
			{
				agenda->lista[i] = agenda->lista[i-1];
				i--;
			}
			agenda->lista[i] = agendamento;
			
			break;
			
		case 4:
			puts("Informe o serviço: ");
			scanf("%s", &agenda->lista[pos].servico);
			break;
		
		case 5:
			puts("Informe se deseja buscar(S/N): ");
			scanf("%d", &agenda->lista[pos].buscar);
			break;
			
			case 10:
				break;
		default:
			puts("Não foi possivel alterar");
			break;
	}
	
}

void exibirLista(LISTA *agenda)
{
	int i=0,j=0;
	
	printf("Agendamentos para o dia: %d\n\n", agenda->numAgendamentos);
	for(i=0;i < agenda->numAgendamentos;i++)
	{
		fflush(stdin);
		printf("Horário:        %d\n", agenda->lista[i].horario);
		printf("Código:         %d\n", agenda->lista[i].codigo);
		printf("Nome:           %s\n",&agenda->lista[i].nomeDono);
		printf("Nome do Animal: %s\n",&agenda->lista[i].nomeAnimal);
		printf("CPF:            %s\n", agenda->lista[i].cpf);
		printf("Serviço:        %s\n",&agenda->lista[i].servico);
		printf("Buscar          %s\n", agenda->lista[i].buscar == 0 ?"Não\n" : "Sim\n");
	}
	if(agenda->numAgendamentos==0)
		puts("Lista Vazia!!! Por enquanto ;)");
	
	limpaTela();
}

void menu(LISTA *agenda)
{
	char escolha='0';
	
	system("cls");
	do
	{
		puts("++  ==  ++    ==    +MENU+    ==    ++  ==  ++");
		puts("\n  Digite um número para acessar a função: \n");
		puts("    Inserir agendamento            (1)");
		puts("    Exibir lista                   (2)");
		puts("    Buscar agendamento(por horário)(3)");
		puts("    Alterar agendamento            (4)");
		puts("    Excluir agendamento            (5)");
		puts("    Gravar remessa de agendamentos (6)");
		puts("\n    Sair                           (0)\n");
		puts("++  ==  ++    ==    ++==++    ==    ++  ==  ++");
		
		printf("\nDigite a escolha: ");
		scanf(" %s",&escolha);
		
		switch(escolha)
		{
			case '0':
				puts("\nVocê escolheu Sair!");
				break;
				
			case '1':
				system("cls");
				inserirAgendamento(agenda);
				break;
				
			case '2':
				system("cls");
				exibirLista(agenda);
				break;
			
			case '3':
				if(agenda->numAgendamentos == 0)
				{
					puts("Nenhum agendamento!!!\n");
					limpaTela();
					break;
				}
				else
				{
					system("cls");
					int b;
					puts("Informe o horário para buscar o agendamento: ");
					scanf("%d", &b);
					buscarAgendamento(agenda, b);
					limpaTela();
					break;
				}
			
			case '4':
				{
					if(agenda->numAgendamentos == 0)
					{
						puts("Nenhum agendamento!!!\n");
						limpaTela();
						break;
					}
					else
					{
						system("cls");
						alterarAgendamento(agenda);
						limpaTela();
						break;	
					}	
				}
			case '5':
				
				if(agenda->numAgendamentos == 0)
				{
					puts("Nenhum agendamento!!!\n");
					limpaTela();
					break;
				}
				else
				{
					system("cls");
					int h;
					puts("Informe o horário para finalizar o agendamento: ");
					scanf("%d", &h);
					excluirAgendamentos(agenda, h);
					limpaTela();
					break;
				}
		
			default: 
				printf("\nNossos desenvolvedores ainda não disponibilizaram essa opção! Verifique...\n");
				limpaTela();
				break;
		}
	}while(escolha != '0');
}

main()
{
	LISTA agenda;
	
	iniciarLista(&agenda);
    setlocale(LC_ALL,"Portuguese");
    menu(&agenda);
    
}//Fim do programa

