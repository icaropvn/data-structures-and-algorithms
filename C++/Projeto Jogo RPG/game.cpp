/*

ESTRUTURAS

- Lista Encadeada...(lista de habilidades do jogador)
- Pilha.............(habilidade de retroceder turnos)
- Fila..............(ordem de jogada)
- Tabela Hash.......(?)
- Árvore............(árvore de habilidades????)

IDEIAS DE IMPLEMENTAÇÃO

- cada classe terá valores diferentes para cada atributo
- haverá combates entre você e mais de um inimigo (usar uma fila para definir a ordem de jogada)
- colocar NÍVEL DO PERSONAGEM na struct dele !!!

- struct dos ITENS
typedef struct {
    string nome, descricao;
    int quantidade;
} Item;

*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <atomic>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

using namespace std;

// variável usada para verificar quando a função assíncrona printDotsLoading() deve parar de executar 
atomic<bool> continuarExecutando(true);

typedef struct {
    string nome, pronome;
    string arquetipo;
    int vida, ataque, defesa;
    // colocar aqui a lista de habilidades
} Personagem;

// função que limpa a tela com o comando correto dependendo do seu SO
void limparTela()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void sleepFor(int milisegundos)
{
    #ifdef _WIN32
        Sleep(milisegundos);
    #else
        sleep(milisegundos / 1000);
    #endif
}

// função assíncrona de animação dos 3 pontos ao finalizar o jogo
void imprimirAnimacaoPontos()
{
    for(int i=0; i<3; i++)
    {
        cout << "." << flush;
        sleepFor(500);
        cout << "." << flush;
        sleepFor(500);
        cout << "." << flush;
        sleepFor(500);
        
        cout << "\b\b\b   " << flush;
        cout << "\b\b\b" << flush;
        sleepFor(500);
    }
}

// função que imprime strings letra a letra, dando a impressão de fala
void imprimirNarracao(string narracao)
{
    
    for(char letra : narracao)
    {
        cout << letra << flush;
        sleepFor(50);
    }
}

// função que imprime o menu e guarda a seleção do usuário
int imprimirMenuPrincipal()
{
    int escolhaMenu;
    
    limparTela();
    
    cout << "=========================================" << endl;
    cout << "             [Nome do jogo]              " << endl;
    cout << "=========================================" << endl;
    cout << endl;
    cout << "[1] Iniciar Jogo" << endl;
    cout << "[2] Sair" << endl;
    
    cin >> escolhaMenu;
    
    return escolhaMenu;
}

// função que direciona as frases de criação de personagem para o feminino
void criarPersonagemPronomeFeminino(Personagem& personagem)
{
    string narracao;
    int escolhaArquetipo;
    
    cout << "> ";
    narracao = "Dentre eles, uma se destacou. O nome dela era: ";
    imprimirNarracao(narracao);
    
    cin >> personagem.nome;
    cout << endl;
    
    cout << "> ";
    narracao = personagem.nome;
    imprimirNarracao(narracao);
    narracao = ", inquieta, se equipava e se preparava para sair em busca de algo maior.";
    imprimirNarracao(narracao);
    cout << endl;
    
    while(true)
    {
        cout << "> ";
        narracao = "Ela foi criada sua vida inteira nesta vila, sempre treinando para se tornar a melhor:";
        imprimirNarracao(narracao);
        cout << endl;
        
        narracao = "[1] Guerreira";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[2] Bruxa";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[3] Assassina";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[4] Cavaleira";
        imprimirNarracao(narracao);
        cout << endl;
        cin >> escolhaArquetipo;
        
        switch(escolhaArquetipo)
        {
            case 1:
                personagem.arquetipo = "Guerreira";
                break;
            case 2:
                personagem.arquetipo = "Bruxa";
                break;
            case 3:
                personagem.arquetipo = "Assassina";
                break;
            case 4:
                personagem.arquetipo = "Cavaleira";
                break;
            default:
                cout << "> ";
                narracao = "Ela ainda não aprendeu as habilidades necessárias para se tornar isso. Vamos tentar de novo!";
                imprimirNarracao(narracao);
                cout << endl;
                break;
        }
        
        if(escolhaArquetipo < 5 && escolhaArquetipo > 0)
            break;
    }
}

// função que direciona as frases de criação de personagem para o masculino
void criarPersonagemPronomeMasculino(Personagem& personagem)
{
    string narracao;
    int escolhaArquetipo;
    
    cout << "> ";
    narracao = "Dentre eles, um se destacou. O nome dele era: ";
    imprimirNarracao(narracao);
    
    cin >> personagem.nome;
    cout << endl;
    
    cout << "> ";
    narracao = personagem.nome;
    imprimirNarracao(narracao);
    narracao = ", inquieto, se equipava e se preparava para sair em busca de algo maior.";
    imprimirNarracao(narracao);
    cout << endl;
    
    while(true)
    {
        cout << "> ";
        narracao = "Ele foi criado sua vida inteira nesta vila, sempre treinando para se tornar o melhor:";
        imprimirNarracao(narracao);
        cout << endl;
        
        narracao = "[1] Guerreiro";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[2] Bruxo";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[3] Assassino";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[4] Cavaleiro";
        imprimirNarracao(narracao);
        cout << endl;
        cin >> escolhaArquetipo;
        
        switch(escolhaArquetipo)
        {
            case 1:
                personagem.arquetipo = "Guerreiro";
                break;
            case 2:
                personagem.arquetipo = "Bruxo";
                break;
            case 3:
                personagem.arquetipo = "Assassino";
                break;
            case 4:
                personagem.arquetipo = "Cavaleiro";
                break;
            default:
                cout << "> ";
                narracao = "Ele ainda não aprendeu as habilidades necessárias para se tornar isso. Vamos tentar de novo!";
                imprimirNarracao(narracao);
                cout << endl;
                break;
        }
        
        if(escolhaArquetipo < 5 && escolhaArquetipo > 0)
            break;
    }
}

// função que conta a história inicial e cria o personagem
void criarPersonagem(Personagem& personagem)
{
    string narracao;
    int pronomePersonagem;
    
    cout << "> Antes de tudo, escolha o pronome do seu personagem:\n[1] Ela\n[2] Ele" << endl;
    cin >> pronomePersonagem;
    
    limparTela();
    
    cout << "> ";
    narracao = "Em um reino distante, guerreiros se erguiam em uma pequena vila denominada [nome da vila].";
    imprimirNarracao(narracao);
    cout << endl;
    
    if(pronomePersonagem == 1)
    {
        personagem.pronome = "Ela";
        criarPersonagemPronomeFeminino(personagem);
    }
    else
    {
        personagem.pronome = "Ele";
        criarPersonagemPronomeMasculino(personagem);
    }
    
    if(personagem.arquetipo == "Guerreira" || personagem.arquetipo == "Guerreiro")
    {
        personagem.vida = 8;
        personagem.ataque = 6;
        personagem.defesa = 6;
    }
    else if(personagem.arquetipo == "Bruxa" || personagem.arquetipo == "Bruxo")
    {
        personagem.vida = 7;
        personagem.ataque = 7;
        personagem.defesa = 6;
    }
    else if(personagem.arquetipo == "Assassina" || personagem.arquetipo == "Assassino")
    {
        personagem.vida = 8;
        personagem.ataque = 8;
        personagem.defesa = 4;
    }
    else
    {
        personagem.vida = 10;
        personagem.ataque = 5;
        personagem.defesa = 5;
    }
}

// função que inicia o jogo e executa todos os comandos para o funcionamento dele
void iniciarJogo()
{
    Personagem personagem;
    
    limparTela();
    
    criarPersonagem(personagem);
    
    
    
    
    int teste;
    
    cout << "\n" << personagem.pronome << endl;
    cout << personagem.nome << endl;
    cout << personagem.arquetipo << endl;
    cout << personagem.ataque << " | " << personagem.defesa << " | " << personagem.vida << endl;
    
    cin >> teste;
}

// função que finaliza o jogo mostrando uma pequena animação
void finalizarJogo()
{
    char confirmarSaida;
    
    limparTela();
    
    cout << "Tem certeza que deseja sair? [s/n]" << endl;
    cin >> confirmarSaida;
    
    switch(confirmarSaida)
    {
        case 's':
            cout << "\nFinalizando o jogo" << flush;
            
            imprimirAnimacaoPontos();
            
            limparTela();
            cout << "\nJogo finalizado. Continue explorando por aí. Até mais.";
            
            exit(0);
            break;
        case 'n':
            break;
    }
}

// função principal que executa todos os comandos necessários para iniciar e finalizar o jogo
int main()
{
    int escolhaMenu;
    
    while(true)
    {
        escolhaMenu = imprimirMenuPrincipal();
        
        switch(escolhaMenu)
        {
            case 1:
                iniciarJogo();
                break;
            case 2:
                finalizarJogo();
                break;
        }
    }

    return 0;
}