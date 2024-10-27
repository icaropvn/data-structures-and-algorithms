/* 001 - Cadastro de Alunos

=== Aula 01 - Exerc�cio 01 ===

Escreva um programa que cadastre at� 30 alunos.
Para cada aluno registre RA, Nome, Parcial, Exame e faltas.

O programa deve ter um menu com as op��es:
Total de Alunos: ??
1) Adicionar
2) Listar
3) Sair

No qual:

* ?? � o n�mero de alunos cadastrados;

* Quando selecionada a op��o listar, os seguintes dados devem ser exibidos em forma de tabela
  CODIGO  NOME  PARCIAL  EXAME  MEDIA FALTAS  STATUS
  
* A exibi��o das notas e m�dias devem ser feitas com 1 casa decimal

* O Status deve exibir APR ou REP de acordo com a regra da institui��o, assim como a M�DIA.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX 3

typedef struct
{
    int codigo, faltas ;
    char nome[50], status[3] ;
    float parcial, exame, media ;
} dados_alunos;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    int i, answer = 1, student_counter = 0;
    dados_alunos aluno[MAX];
    
    do
    {
        if(answer == 1)
        {
            if(student_counter < MAX)
            {
                printf("Codigo (RA): ");
                scanf("%i", &aluno[student_counter].codigo);
                
                printf("Nome: ");
                scanf(" %50[^\n]s", aluno[student_counter].nome);
                fflush(stdin);
                
                printf("Nota da prova parcial: ");
                scanf("%f", &aluno[student_counter].parcial);
                    
                printf("Nota do exame: ");
                scanf("%f", &aluno[student_counter].exame);
                
                aluno[student_counter].media = 0.4 * aluno[student_counter].parcial + 0.6 * aluno[student_counter].exame ;
                
                if(aluno[student_counter].media >= 6.0)
                    strcpy(aluno[student_counter].status, "APR");
                else
                    strcpy(aluno[student_counter].status, "REP");
                    
                printf("Faltas do aluno: ");
                scanf("%i", &aluno[student_counter].faltas);
                
                student_counter++ ;
            }
            else
                printf("QUANTIDADE M�XIMA DE ALUNOS CADASTRADOS\n");
        }
        else if(answer == 2)
        {
            printf("-------------------------------------------------------------------------------------------------------------------\n");
            printf(" C�digo  |                       Nome                       |  Parcial  |  Exame  |  M�dia  |  Faltas  |  Status  |\n");
            
            for(i=0; i<student_counter; i++)
            {
                printf(" %6.i  | %48s |  %7.1f  |  %5.1f  |  %5.1f  |  %6.i  |     %s  |\n", aluno[i].codigo, aluno[i].nome, aluno[i].parcial, aluno[i].exame, aluno[i].media, aluno[i].faltas, aluno[i].status);
                if(i == student_counter - 1)
                    printf("-------------------------------------------------------------------------------------------------------------------\n");
            }
            
        }
        else
            printf("Resposta inv�lida.\n");
        
        printf("\nTotal de alunos: %i\n1) Adicionar\n2) Listar\n3) Sair\nR: ", student_counter);
        scanf("%i", &answer);
        
        printf("\n");
        
    } while(answer != 3);
    
    printf("At� a pr�xima!\n");
    
    return 0;
}
