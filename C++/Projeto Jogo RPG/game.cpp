/*

- struct dos ITENS
typedef struct {
    string nome, descricao;
    int quantidade;
} Item;

*/

#include <iostream>
// #include <boost/locale.hpp>
#include <string>
#include <initializer_list>
#include <sstream>
#include <random>
#include <thread>

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
#else
    #include <unistd.h>
    #include <cstdlib>
#endif

using namespace std;

// estrutura que define as variáveis relacionadas ao personagem do jogador
typedef struct {
    string nome, pronome;
    string arquetipo;
    int vida, ataque, defesa;
    int exp, nivel;
    // vetor de habilidades
} Personagem;

// estrutura das habilidades dos inimigos
typedef struct {
    string nomeHabilidade;
    int danoHabilidade;
} HabilidadeInimigo;

typedef struct {
    string nomeContraAtaque, descricaoContraAtaque;
    int danoContraAtaque;
} ContraAtaquesInimigo;

// estrutura que define as variáveis relacionadas aos inimigos
typedef struct {
    string nome;
    int vida, ataque, defesa;
    HabilidadeInimigo habilidades[3];
    ContraAtaquesInimigo contraAtaques[2];
} Inimigo;

// estrutura dos nós da FILA DE COMBATE
typedef struct noFilaCombate {
    string nome;
    struct noFilaCombate *proximo;
} noFilaCombate;

// estrutura principal da FILA DE COMBATE
typedef struct {
    noFilaCombate *frente;
    noFilaCombate *tras;
    int tam;
} FilaCombate;

void criarFilaCombate(FilaCombate& filaCombate)
{
    filaCombate.frente = nullptr;
	filaCombate.tras = nullptr;
	filaCombate.tam = 0;
}

void enfileirarCriaturasCombate(FilaCombate& filaCombate, string criatura)
{
    noFilaCombate *novo_no = new noFilaCombate;
    
    if(novo_no)
	{
		novo_no -> nome = criatura;
		novo_no -> proximo = nullptr;
		
		if(filaCombate.frente == nullptr)
			filaCombate.frente = novo_no;
		else
			filaCombate.tras->proximo = novo_no;

        filaCombate.tras = novo_no;
		
		filaCombate.tam++;
	}
	else
		cout << "\n\nAlgo deu errado ao enfileirar as criaturas para o combate\n\n";
}

void imprimirFilaCombate(FilaCombate& filaCombate)
{
	noFilaCombate *aux = filaCombate.frente;
	
	printf("\n------ Queue / Itens: %02i ------\n", filaCombate.tam);
	
	while(aux)
	{
		cout << aux->nome << endl;
		aux = aux->proximo;
	}
	
	printf("\n---------- Queue End ----------\n\n");
}

// funÃ§Ã£o que limpa a tela com o comando correto dependendo do seu SO
void limparTela()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// funÃ§Ã£o que pausa a execuÃ§Ã£o do programa com base no SO
void pausar(int milisegundos)
{
    #ifdef _WIN32
        Sleep(milisegundos);
    #else
        usleep(milisegundos * 1000);
    #endif
}

// funÃ§Ã£o de animaÃ§Ã£o dos 3 pontos ao finalizar o jogo
void imprimirAnimacaoPontos()
{
    for(int i=0; i<3; i++)
    {
        cout << "." << flush;
        pausar(500);
        cout << "." << flush;
        pausar(500);
        cout << "." << flush;
        pausar(500);
        
        cout << "\b\b\b   " << flush;
        cout << "\b\b\b" << flush;
        pausar(500);
    }
}

// funÃ§Ã£o que imprime strings letra a letra, dando a impressÃ£o de fala
void imprimirNarracao(string narracao)
{
    for(char letra : narracao)
    {
        cout << letra << flush;
        pausar(50);
    }
}

// funÃ§Ã£o que espera uma tecla qualquer do teclado para continuar a execuÃ§Ã£o
void esperarTeclaParaContinuar()
{
    #ifdef _WIN32
        cout << "Pressione a tecla enter para continuar...\n";
        _getch();
    #else
        cout << "Pressione a tecla enter para continuar...\n";
        system("read -r -p \"\" key");
    #endif
}

void contraAtaquesInimigo(Inimigo& inimigo, int escolhaDoJogador)
{
    string narracao;
    ostringstream valorConvertido;
    int dano;

    ContraAtaquesInimigo contraAtaque = inimigo.contraAtaques[escolhaDoJogador-2];

    dano = contraAtaque.danoContraAtaque;
    dano -= inimigo.defesa;
    inimigo.vida -= dano;

    valorConvertido << dano;

    cout << "> ";
    narracao = contraAtaque.descricaoContraAtaque;
    imprimirNarracao(narracao);
    cout << endl;

    if(dano > 0)
    {
        cout << "> ";
        narracao = "Você causou ";
        imprimirNarracao(narracao);
        narracao = valorConvertido.str();
        imprimirNarracao(narracao);
        narracao = " de dano ao ";
        imprimirNarracao(narracao);
        narracao = inimigo.nome;
        imprimirNarracao(narracao);
        narracao = ".";
        imprimirNarracao(narracao);
        cout << endl;
    }
    else
    {
        cout << "> ";
        narracao = "Apesar das suas habilidades, não foi suficiente para abalar a criatura.";
        imprimirNarracao(narracao);
        cout << endl;

        cout << "> ";
        narracao = "Todo o dano foi absorvido pela defesa da criatura.";
        imprimirNarracao(narracao);
        cout << endl;
    }
    
    valorConvertido.str("");
    valorConvertido.clear();

    cout << endl;
}

void imprimirAcoesUnicas(Inimigo inimigo, int& contadorDeAcoes)
{
    string narracao;
    ostringstream contadorDeAcoesConvertido;

    for(int i=0; i<2; i++)
    {
        contadorDeAcoesConvertido << contadorDeAcoes;

        cout << "> ";
        narracao = "[";
        imprimirNarracao(narracao);
        narracao = contadorDeAcoesConvertido.str();
        imprimirNarracao(narracao);
        narracao = "] ";
        imprimirNarracao(narracao);
        narracao = inimigo.contraAtaques[i].nomeContraAtaque;
        imprimirNarracao(narracao);
        cout << endl;

        contadorDeAcoesConvertido.str("");
        contadorDeAcoesConvertido.clear();
        contadorDeAcoes++;
    }
}

void executarAcaoJogadorCombate(int escolhaDoJogador, Personagem personagem, Inimigo& inimigo)
{
    string narracao;
    ostringstream valorConvertido;
    int dano;

    switch(escolhaDoJogador)
    {
        case 1:
            dano = personagem.ataque - inimigo.defesa;
            inimigo.vida -= dano;

            valorConvertido << dano;

            cout << "> ";
            narracao = "Você causou ";
            imprimirNarracao(narracao);
            narracao = valorConvertido.str();
            imprimirNarracao(narracao);
            narracao = " de dano ao ";
            imprimirNarracao(narracao);
            narracao = inimigo.nome;
            imprimirNarracao(narracao);
            narracao = ".";
            imprimirNarracao(narracao);
            cout << endl;
            cout << endl;

            valorConvertido.str("");
            valorConvertido.clear();

            break;
        case 2:
        case 3:
            contraAtaquesInimigo(inimigo, escolhaDoJogador);
            break;
    }
}

void combate(Personagem personagem, initializer_list<Inimigo*> inimigos)
{
    FilaCombate filaCombate;
    string narracao;
    Inimigo* inimigoMarcado = nullptr;
    int contadorDeAcoes = 1, escolhaDoJogador, contadorDeInimigos = 0, marcador, habilidadeInimigoEscolhida, dano;
    ostringstream contadorDeAcoesConvertido;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 2);
    
    criarFilaCombate(filaCombate);
    enfileirarCriaturasCombate(filaCombate, personagem.nome);
    
    for(auto inimigo : inimigos)
    {
        enfileirarCriaturasCombate(filaCombate, inimigo->nome);
        contadorDeInimigos++;
    }
    
    contadorDeInimigos--;
    noFilaCombate *aux = filaCombate.frente;
    
    while(true)
    {
        // ajustar para imprimir com animacao
        // ajustar para se adequar à quantidade de inimigos
        cout << "> ";
        narracao = "Sua vida: " + to_string(personagem.vida);
        imprimirNarracao(narracao);
        cout << endl;

        for(auto inimigo : inimigos)
        {
            cout << "> ";
            narracao = "Vida do " + inimigo->nome + ": " + to_string(inimigo->vida);
            imprimirNarracao(narracao);
            cout << endl;
        }

        cout << endl;

        if(aux->nome == personagem.nome)
        {
            if(contadorDeInimigos > 0)
            {
                cout << "> ";
                narracao = "É a sua vez! Escolha qual inimigo atacar:";
                imprimirNarracao(narracao);
                cout << endl;
                cout << endl;
                
                for(auto inimigo : inimigos)
                {
                    if(!inimigo->nome.empty())
                    {
                        contadorDeAcoesConvertido << contadorDeAcoes;
                        
                        cout << "> ";
                        narracao = "[";
                        imprimirNarracao(narracao);
                        narracao = contadorDeAcoesConvertido.str();
                        imprimirNarracao(narracao);
                        narracao = "] ";
                        imprimirNarracao(narracao);
                        narracao = inimigo->nome;
                        imprimirNarracao(narracao);
                        cout << endl;
                        
                        contadorDeAcoesConvertido.str("");
                        contadorDeAcoesConvertido.clear();
                        contadorDeAcoes++;
                    }
                }
                
                cin >> marcador;
                marcador--;
                inimigoMarcado = inimigos.begin()[marcador];
                
                contadorDeAcoes = 1;
            }
            else
            {
                cout << "> ";
                narracao = "É a sua vez! Como você irá agir?";
                imprimirNarracao(narracao);
                cout << endl;

                inimigoMarcado = inimigos.begin()[0];
            }

            cout << endl;
            cout << "> ";
            narracao = "[1] Golpear";
            imprimirNarracao(narracao);
            cout << endl;
            contadorDeAcoes++;
            
            imprimirAcoesUnicas(*inimigoMarcado, contadorDeAcoes);
            
            contadorDeAcoesConvertido << contadorDeAcoes;
            
            cout << "> ";
            narracao = "[";
            imprimirNarracao(narracao);
            narracao = contadorDeAcoesConvertido.str();
            imprimirNarracao(narracao);
            narracao = "] Checar Inventário";
            imprimirNarracao(narracao);
            cout << endl;
            
            cin >> escolhaDoJogador;

            cout << endl;
            executarAcaoJogadorCombate(escolhaDoJogador, personagem, *inimigoMarcado);
        }
        else
        {
            habilidadeInimigoEscolhida = dis(gen);
            
            for(auto inimigo : inimigos)
            {
                if(aux->nome == inimigo->nome)
                    inimigoMarcado = inimigo;
            }
            
            dano = inimigoMarcado->habilidades[habilidadeInimigoEscolhida].danoHabilidade - personagem.defesa;

            if(dano > 0)
            {
                personagem.vida -= dano;

                cout << endl;
                cout << "> ";
                narracao = inimigoMarcado->nome + " usou a habilidade " + inimigoMarcado->habilidades[habilidadeInimigoEscolhida].nomeHabilidade + " e causou " + dano + " de dano a você.";
                imprimirNarracao(narracao);
                cout << endl;
            }
            else
            {
                cout << "> ";
                narracao = "A criatura tenta te atacar de diversas formas, mas você tem experiência com isso; e sua armadura é bastante resistente.";
                imprimirNarracao(narracao);
                cout << endl;

                cout << "> ";
                narracao = "Todo o dano foi absorvido pela sua defesa.";
                imprimirNarracao(narracao);
                cout << endl;
                cout << endl;
            }
            
            esperarTeclaParaContinuar();
            cout << endl;
        }
        
        aux = aux->proximo;
        
        if(aux == nullptr)
            aux = filaCombate.frente;
        
        contadorDeAcoesConvertido.str("");
        contadorDeAcoesConvertido.clear();
        contadorDeAcoes = 1;
        
        bool todosInimigosDerrotados = true;

        for(auto inimigo : inimigos)
        {
            if(inimigo->vida > 0)
                todosInimigosDerrotados = false;
        }

        if(todosInimigosDerrotados == true || personagem.vida <= 0)
            break;
    }

    // aqui inserir o destrutor da FILA DE COMBATE
}

// função que imprime o menu e guarda a seleção do usuário
int imprimirMenuPrincipal()
{
    int escolhaMenu;
    
    while(true)
    {
        limparTela();
    
        cout << "=========================================" << endl;
        cout << "             [Nome do jogo]              " << endl;
        cout << "=========================================" << endl;
        cout << endl;
        cout << "[1] Iniciar Jogo" << endl;
        cout << "[2] Sair" << endl;
        
        cin >> escolhaMenu;
        
        if(escolhaMenu != 1 && escolhaMenu != 2)
        {
            cout << "Desculpe! Não temos a opção inserida, ainda..." << flush;
            pausar(4000);
        }
        else
            break;
    }
    
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
    
    while(true)
    {
        limparTela();
    
        cout << "> Antes de tudo, escolha o pronome do seu personagem:" << endl;
        cout << "[1] Ela" << endl;
        cout << "[2] Ele" << endl;
        cin >> pronomePersonagem;
        
        if(pronomePersonagem == 1 || pronomePersonagem == 2)
            break;
        else
        {
            cout << endl;
            cout << "Infelizmente não temos esse pronome disponível no momento..." << flush;
            pausar(4000);
        }
    }
    
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
    
    personagem.exp = 0;
    personagem.nivel = 1;

    // inicializar a lista de habilidades aqui com base no arquetipo escolhido
}

// função que executa os comandos caso o jogador decida se juntar à Têmis
void respostaCasoAceitarProposta()
{
    string narracao;
    
    limparTela();
    
    cout << "> [Têmis] - ";
    narracao = "Fez a escolha certa, criança.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> [Têmis] - ";
    narracao = "O que eu sei até então é que muitas criaturas esquisitas têm aparecido pelos lados de {nome de algum lugar}. Talvez seja interessante começar por lá.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> [Têmis] - ";
    narracao = "Infelizmente não posso te acompanhar no momento, mas acredito que isto te servirá para alguma coisa. Boa sorte.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    cout << "> ";
    narracao = "Você recebeu um saco com 3 pequenos frascos vermelhos borbulhantes.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> ";
    narracao = "3 Frascos de cicatrização adicionados ao INVENTÁRIO.";
    imprimirNarracao(narracao);
    cout << endl;
    
    // aqui adicionar o item ao inventÃ¡rio via Tabela Hash
    
    esperarTeclaParaContinuar();
}

// função que executa os comandos caso o jogador decida não se juntar à Têmis
void respostaCasoRecusarProposta()
{
    string narracao;
    
    limparTela();
    
    cout << "> [Têmis] - ";
    narracao = "Como quiser. Boa sorte na sua jornada.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << ">  ";
    narracao = "A pessoa misteriosa se desvanece em meio a uma fumaça na sua frente, deixando um sí­mbolo marcado no chão.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << ">  ";
    narracao = "Você percebe um acúmulo de um pó cinza no local. Sua curiosidade fala mais alto. Você guarda o pó em um frasco para mais tarde.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    cout << ">  ";
    narracao = "1 Pote de Cinzas Espirituais adicionado ao INVENTÁRIO.";
    imprimirNarracao(narracao);
    cout << endl;
    
    // aqui adicionar o item ao inventÃ¡rio via Tabela Hash
    
    esperarTeclaParaContinuar();
}

// função que direciona a conversa do prólogo para o fluxo 1.1
void respostaCaso1o1()
{
    string narracao;
    int resposta;
    
    limparTela();
    
    cout << "> [Têmis] - ";
    narracao = "Receio que temos um interesse em comum. Parti de minha vila há um tempo para descobrir o que são os acontecimentos recentes.";
    imprimirNarracao(narracao);
    cout << endl;
    
    while(true)
    {
        cout << "> [Têmis] - ";
        narracao = "Imagino que queira se juntar a mim para descobrir o que está havendo, o que acha? Podemos decifrar juntos o que as pessoas têm chamado de \"Apocalipse\".";
        imprimirNarracao(narracao);
        cout << endl;
        cout << endl;
        
        narracao = "[1] (Se juntar)";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[2] (Continuar de forma independente)";
        imprimirNarracao(narracao);
        cout << endl;
        
        cin >> resposta;
        
        if(resposta < 1 || resposta > 2)
        {
            cout << "Resposta indisponí­vel... Vamos tentar de novo!" << flush;
            pausar(5000);
            limparTela();
        }
        else
            break;
    }
    
    switch(resposta)
    {
        case 1:
            respostaCasoAceitarProposta();
            break;
        case 2:
            respostaCasoRecusarProposta();
            break;
    }
    
}

// função que direciona a conversa do prólogo para o fluxo 1.2
void respostaCaso1o2()
{
    string narracao;
    int resposta;

    while(true)
    {
        cout << "> [Têmis] - ";
        narracao = "Me encontro em um momento de muita descoberta dos mistérios recentes. Talvez essas armas que carrega podem ser úteis. O que acha de me acompanhar?";
        imprimirNarracao(narracao);
        cout << endl;
        cout << endl;
                
        narracao = "[1] (Se juntar)";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[2] (Continuar de forma independente)";
        imprimirNarracao(narracao);
        cout << endl;
        
        cin >> resposta;
        
        if(resposta < 1 || resposta > 2)
        {
            cout << "Resposta indisponí­vel... Vamos tentar de novo!" << flush;
            pausar(5000);
            limparTela();
        }
        else
            break;
    }

    switch(resposta)
    {
        case 1:
            respostaCasoAceitarProposta();
            break;
        case 2:
            respostaCasoRecusarProposta();
            break;
    }
}

// função que direciona a conversa do prólogo para o fluxo 1
void respostaCaso1()
{
    string narracao;
    int resposta;
    
    limparTela();
    
    cout << "> [???] - ";
    narracao = "A aurora cativa essas planí­cies. Acredito que queira voltar sempre que puder.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> [???] - ";
    narracao = "Eu, a propósito, estou aqui em busca de algo. Prazer, me chamo Têmis.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    cout << "> ";
    narracao = "O ser misterioso retira o capuz de cor marrom, revelando um rosto de uma mulher cansada, como quem já viu coisas demais.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    esperarTeclaParaContinuar();
    
    while(true)
    {
        limparTela();
    
        cout << "> [Têmis] - ";
        narracao = "Acredito que tenha percebido os estranhos acontecimentos recentes. Vejo que carrega armas, para que são?";
        imprimirNarracao(narracao);
        cout << endl;
        cout << endl;
        
        narracao = "[1] Estou as levando em minha jornada. Quero desvendar o que tem acontecido ao redor destes vilarejos.";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[2] São apenas por garantia. Não pretendo usá-las para fins que não seja defesa pessoal.";
        imprimirNarracao(narracao);
        cout << endl;
        
        cin >> resposta;
        
        if(resposta < 1 || resposta > 2)
        {
            cout << "Resposta indisponí­vel... Vamos tentar de novo!" << flush;
            pausar(5000);
        }
        else
            break;
    }
    
    switch(resposta)
    {
        case 1:
            respostaCaso1o1();
            break;
        case 2:
            respostaCaso1o2();
            break;
    }
}

// função que direciona a conversa do prólogo para o fluxo 2
void respostaCaso2()
{
    string narracao;
    int resposta;

    limparTela();

    cout << "> [???] - ";
    narracao = "Por sorte encontrou alguém com o mesmo objetivo que você. Esses acontecimentos têm me intrigado por semanas.";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "> [???] - ";
    narracao = "Meu nome é Têmis, por sinal. Moro em uma vila a não muito tempo daqui. As pessoas lá não sabem mais o que fazer em relação às coisas estranhas que têm acontecido.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    cout << "> ";
    narracao = "O ser misterioso retira o capuz de cor marrom, revelando um rosto de uma mulher cansada, como quem já viu coisas demais.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    esperarTeclaParaContinuar();
    limparTela();

    cout << "> [Têmis] - ";
    narracao = "Por isso, decidi eu mesma ir atrás desse mistério. Já fiz muito progresso.";
    imprimirNarracao(narracao);
    cout << endl;

    while(true)
    {
        cout << "> [Têmis] - ";
        narracao = u8"Uma ajuda extra seria muito bem-vinda. O que acha de ouvir um pouco sobre o que tenho a dizer sobre essa situação?";
        imprimirNarracao(narracao);
        cout << endl;
        cout << endl;
        narracao = "[1] (Se juntar)";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[2] (Continuar de forma independente)";
        imprimirNarracao(narracao);
        cout << endl;
        
        cin >> resposta;
        
        if(resposta < 1 || resposta > 2)
        {
            cout << "Resposta indisponÃ­vel... Vamos tentar de novo!" << flush;
            pausar(5000);
            limparTela();
        }
        else
            break;
    }

    switch(resposta)
    {
        case 1:
            respostaCasoAceitarProposta();
            break;
        case 2:
            respostaCasoRecusarProposta();
            break;
    }
}

// função que direciona a conversa do prólogo para o fluxo 3
void respostaCaso3()
{
    string narracao;

    limparTela();

    cout << "> [???] - ";
    narracao = "Nesse caso, meu nome também não lhe diz respeito. Trilhe seu caminho sem incômodos, mas se atente aos perigos dessa estrada. Nem tudo são rosas se visto muito de perto.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    cout << "> ";
    narracao = "A pessoa misteriosa se desvanece em meio a uma fumaça na sua frente, deixando um sí­mbolo marcado no chão.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    cout << "> ";
    narracao = "Você percebe um acúmulo de um pó cinza no local. Sua curiosidade fala mais alto. Você guarda o pó em um frasco para mais tarde.";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "> ";
    narracao = "1 Pote de Cinzas Espirituais adicionado ao INVENTÁRIO.";
    imprimirNarracao(narracao);
    cout << endl;

    // adicionar item ao inventario aqui
    
    esperarTeclaParaContinuar();
}

// função que executa o prólogo do jogo
void prologo()
{
    string narracao;
    int resposta;
    
    limparTela();
    
    cout << "> ";
    narracao = u8"Você se encontra saindo da vila onde viveu sua vida toda, em busca de algo que tem perturbado a paz dos moradores locais.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> ";
    narracao = u8"Plantações mortas, desastres naturais, animais doentes por causas desconhecidas, e nada de respostas.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    esperarTeclaParaContinuar();
    limparTela();
    
    cout << "> ";
    narracao = u8"Durante seu caminhar através de uma estreita estrada de calcário, algo chama sua atenção: um ser encapuzado.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> ";
    narracao = u8"Você se aproxima, apesar da aflição.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    esperarTeclaParaContinuar();
    
    while(true)
    {
        limparTela();
        
        cout << "> [???] - ";
        narracao = u8"O que anda fazendo por essas bandas, criança?";
        imprimirNarracao(narracao);
        cout << endl;
        cout << endl;
        
        narracao = "[1] Apenas dando uma passeada, e o senhor?";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[2] Estou procurando algo que está causando desordem em minha vila.";
        imprimirNarracao(narracao);
        cout << endl;
        narracao = "[3] Não lhe diz respeito. Quem seria você por sinal?";
        imprimirNarracao(narracao);
        cout << endl;
        
        cin >> resposta;
        
        if(resposta < 1 || resposta > 3)
        {
            cout << "Resposta indisponível... Vamos tentar de novo!" << flush;
            pausar(5000);
        }
        else
            break;
    }
    
    switch(resposta)
    {
        case 1:
            respostaCaso1();
            break;
        case 2:
            respostaCaso2();
            break;
        case 3:
            respostaCaso3();
            break;
    }
}

void addInimigo(Inimigo& inimigo, string nome, int vida, int ataque, int defesa, HabilidadeInimigo habilidades[3], ContraAtaquesInimigo contraAtaques[2])
{
    inimigo.nome = nome;

    inimigo.vida = vida;
    inimigo.ataque = ataque;
    inimigo.defesa = defesa;
    
    for(int i=0; i<3; i++)
    {
        inimigo.habilidades[i] = habilidades[i];
        
        if(i<2)
            inimigo.contraAtaques[i] = contraAtaques[i];
    }
}

void introducaoInimigoUm(Personagem personagem)
{
    Inimigo druidaAssombrado;
    
    HabilidadeInimigo habilidades[] = {
        {"Agarrar", 5},
        {"Envolver em Trevas", 6},
        {"A Maldição da Floresta", 8}
    };

    ContraAtaquesInimigo contraAtaques[] = {
        {"Purificar", "Você usa as histórias que ouvia quando era criança para proferir orações que livram esta alma maldita de seu estado decadente.", 9},
        {"Usar a força da natureza", "Você não está apto a controlar a natureza. A criatura sente seus movimentos e absorve quase todos.", 1}
    };

    addInimigo(druidaAssombrado, "Druida Assombrado", 15, 1, 2, habilidades, contraAtaques);
       
    limparTela();
    
    combate(personagem, {&druidaAssombrado});
}

void introducaoEntrarNaFloresta(Personagem personagem)
{
    string narracao;
    
    limparTela();
    
    cout << "> ";
    narracao = "Com apreensão e entusiasmo, você se dirige à trilha banhada de dor, é inevitável se assustar com a aparência dessa floresta.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> ";
    narracao = "As árvores se assemelham a tentáculos de um enorme polvo emergindo do solo, se contorcendo e entrelaçando nelas mesmas.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> ";
    narracao = "Um ar pesado toma seu corpo. Seu caminhar se torna mais cuidadoso. Há algo por perto.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    esperarTeclaParaContinuar();
    limparTela();

    cout << "> ";
    narracao = "De forma bestial, um vulto negro se lança em sua direção a partir de folhagens escuras.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    cout << "> ";
    narracao = "UM INIMIGO APARECEU!";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    esperarTeclaParaContinuar();
    
    introducaoInimigoUm(personagem);
}

void introducao(Personagem personagem)
{
    string narracao;
    int escolha;

    limparTela();
    
    cout << "> ";
    narracao = "Você observa traços decadentes a partir de uma parte da trilha.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    while(true)
    {
        cout << "> ";
        narracao = "Faça sua escolha:";
        imprimirNarracao(narracao);
        cout << endl;
        
        cout << "> ";
        narracao = "[1] Checar inventário";
        imprimirNarracao(narracao);
        cout << endl;

        cout << "> ";
        narracao = "[2] Seguir o caminho da decadência";
        imprimirNarracao(narracao);
        cout << endl;

        cin >> escolha;

        if(escolha < 1 || escolha > 2)
        {
            cout << endl;
            cout << "Faça uma das escolhas propostas. Não fuja disso.";
            pausar(4000);
            limparTela();
        }
        else
            break;
    }
    
    switch(escolha)
    {
        case 1:
            limparTela();
            cout << "Este é a sua bolsa. Aqui você pode guardar tudo o que achar em sua jornada." << endl;
            cout << endl;
            // imprimir inventario;
            break;
        case 2:
            introducaoEntrarNaFloresta(personagem);
            break;
    }

}

// função que inicia o jogo e executa todos os comandos para o funcionamento dele
void iniciarJogo()
{
    Personagem personagem;
    
    criarPersonagem(personagem);
    
    // prologo();

    introducao(personagem);
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
            cout << "Jogo finalizado. Continue explorando por aí­. Até mais.";
            
            exit(0);
            break;
        case 'n':
            break;
    }
}

// função principal que executa todos os comandos necessários para iniciar e finalizar o jogo
int main()
{
    system("chcp 1252 > nul");

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