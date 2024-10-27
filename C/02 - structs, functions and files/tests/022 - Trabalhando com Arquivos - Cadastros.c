#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* Este � um algoritmo de cadastro de alunos que simula um banco de dados
atrav�s de um arquivo .txt. */

// defini��o da struct que cont�m os dados de cada aluno
typedef struct
{
    int code;
    char name[50];
    float parcial_grade, exam_grade, avarage;
} studentData;

void flushBuffer();

void menu(studentData students[], int *counter);
    void selectOption(int answer, studentData students[], int *counter);
        void registerNewStudent(studentData students[], int *counter);
            void pullDataDocument(studentData students[], int *counter);
            void getDataNewRegister(studentData students[], int *counter);
            void sortStudents(studentData students[], int counter);
            void writeRegistersDocument(studentData students[], int counter);
        void showRegisters(studentData students[]);

int verifyErrorFile(FILE *file);

// fun��o principal: declara o idioma da lib "locale.h" e declara os dados base. Invoca o Menu
int main()
{
	setlocale(LC_ALL, "Portuguese");
	
    studentData students[60];
    int counter = 0;
    
    menu(students, &counter);
    
    return 0;
}

// fun��o que limpa o buffer do teclado de maneira mais direta e segura em rela��o ao 'fflush(stdin)'
void flushBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// fun��o Menu que coleta a op��o desejada do usu�rio e invoca a fun��o que determina o caminho certo
void menu(studentData students[], int *counter)
{
    int answer = 0;
    
    while(answer != 3)
    {
        printf("Escolha uma op��o:\n");
        printf("[1] Cadastrar Novo Aluno\n[2] Exibir Alunos Cadastrados\n[3] Sair\nR: ");
        scanf("%i", &answer);
        
        selectOption(answer, students, &*counter);
    }
}

// fun��o que determina a execu��o do algoritmo de acordo com a escolha do usu�rio
void selectOption(int answer, studentData students[], int *counter)
{
    switch(answer)
    {
        case 1:
            registerNewStudent(students, &*counter);
            break;
        case 2:
            showRegisters(students);
            break;
        case 3:
            printf("\nAt� mais!");
            break;
        default:
            printf("\nOp��o Inv�lida.\n-----------------------------");
            break;
    }
    
    printf("\n");
}

// fun��o geral que define a ordem das fun��es para a execu��o da l�gica do registro de um novo aluno
void registerNewStudent(studentData students[], int *counter)
{
    pullDataDocument(students, &*counter);
    
    getDataNewRegister(students, &*counter);
        
    sortStudents(students, *counter);
        
    writeRegistersDocument(students, *counter);
}

// fun��o que l� e atribui ao vetor os dados do arquivo txt
void pullDataDocument(studentData students[], int *counter)
{
    FILE *file;
    
    file = fopen("022 - Lista de Cadastros.txt", "r");
    *counter = 0;
    
    if(!verifyErrorFile(file))
    {
        while(fscanf(file, "%i %s %f %f %f", &students[*counter].code, students[*counter].name, &students[*counter].parcial_grade, &students[*counter].exam_grade, &students[*counter].avarage) != EOF)
            (*counter)++;
    }
    
    fclose(file);
}

// fun��o que coleta os dados do novo registro do usu�rio e atribui ao final do vetor
void getDataNewRegister(studentData students[], int *counter)
{
    printf("\nInsira o c�digo do aluno: ");
    scanf("%6i", &students[*counter].code);
    flushBuffer();
        
    printf("Insira o nome do aluno: ");
    scanf(" %50[^\n]", students[*counter].name);
    flushBuffer();
        
    printf("Insira a nota parcial: ");
    scanf("%f", &students[*counter].parcial_grade);
        
    printf("Insira a nota do exame: ");
    scanf("%f", &students[*counter].exam_grade);
        
    students[*counter].avarage = students[*counter].parcial_grade * 0.4 + students[*counter].exam_grade * 0.6;
        
    (*counter)++;
}

// fun��o que ordena o vetor de dados em ordem crescente de c�digo
void sortStudents(studentData students[], int counter)
{
	int i, j;
	studentData aux;
	
	for(i=0; i<counter; i++)
	{
		for(j=0; j<counter-1; j++)
		{
			if(students[j].code > students[j+1].code)
			{		    
				aux = students[j];
				students[j] = students[j+1];
				students[j+1] = aux;
			}
		}
	}
}

// fun��o que retorna o vetor j� ordenado e implementado com novo registro ao arquivo txt
void writeRegistersDocument(studentData students[], int counter)
{
    FILE *file;
    int i;
    
    file = fopen("022 - Lista de Cadastros.txt", "w");
    
    for(i=0; i<counter; i++)
    {
        fprintf(file, "%6i  %50s  %5.2f  %5.2f  %5.2f\n", students[i].code, students[i].name, students[i].parcial_grade, students[i].exam_grade, students[i].avarage);
    }
    
    fclose(file);
}

// fun��o que mostra em forma de tabela todos os dados encontrados no arquivo txt
void showRegisters(studentData students[])
{
    int code;
    char name[50];
    float parcial_grade, exam_grade, avarage;
    
    FILE *file = fopen("022 - Lista de Cadastros.txt", "r");
    
    printf("\n|-- RA --|----------------------- NOME -----------------------|- PARCIAL -|- EXAME -|- M�DIA -|\n");
    
    if(!verifyErrorFile(file))
    {
        while(fscanf(file, "%i %s %f %f %f", &code, name, &parcial_grade, &exam_grade, &avarage) != EOF )
        {
            printf("| %6i | %50s | %9.2f | %7.2f | %7.2f |\n", code, name, parcial_grade, exam_grade, avarage);
        }
        
        printf("|---------------------------------------------------------------------------------------------|\n");
        
        fclose(file);
    }
}

// fun��o geral que verifica o retorno da tentativa de abrir o arquivo, se for NULL, mensagem apropriada � escrita
int verifyErrorFile(FILE *file)
{
    if(file == NULL)
    {
        printf("\nAlgo deu errado. Arquivo pode estar corrompido.\n");
        return 1;
    }
    
    return 0;
}
