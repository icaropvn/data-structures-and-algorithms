/*

IDEIAS DE IMPLEMENTAÇÃO

- haverá combates entre você e mais de um inimigo (usar uma fila para definir a ordem de jogada)
- colocar NÍVEL DO PERSONAGEM na struct dele !!!

- struct dos ITENS
typedef struct {
    string nome, descricao;
    int quantidade;
} Item;

*/

#include <iostream>
// #include <boost/locale.hpp>
#include <string>
#include <atomic>

#ifdef _WIN32
    #include <windows.h>
    #include <conio.h>
#else
    #include <unistd.h>
    #include <cstdlib>
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

// função que pausa a execução do programa com base no SO
void pausar(int milisegundos)
{
    #ifdef _WIN32
        Sleep(milisegundos);
    #else
        usleep(milisegundos * 1000);
    #endif
}

// função assíncrona de animação dos 3 pontos ao finalizar o jogo
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

// função que imprime strings letra a letra, dando a impressão de fala
void imprimirNarracao(string narracao)
{
    for(char letra : narracao)
    {
        cout << letra << flush;
        pausar(50);
    }
}

// função que espera uma tecla qualquer do teclado para continuar a execução
void esperarTeclaParaContinuar()
{
    #ifdef _WIN32
        cout << "Pressione qualquer tecla para continuar...\n";
        _getch();
    #else
        cout << "Pressione qualquer tecla para continuar...\n";
        system("read -r -p \"\" key");
    #endif
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
    
    // inicializar a lista de habilidades aqui com base no arquetipo escolhido
}

// função que executa os comandos caso o jogador decida se juntar à Têmis
void respostaCasoAceitarProposta()
{
    string narracao;
    
    limparTela();
    
    cout << "> [Têmis] - ";
    narracao = u8"Fez a escolha certa, criança.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> [Têmis] - ";
    narracao = u8"O que eu sei até então é que muitas criaturas esquisitas têm aparecido pelos lados do Reino de Magmar. Talvez seja interessante ir por lá.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> [Têmis] - ";
    narracao = u8"Infelizmente não posso te acompanhar no momento, mas acredito que isso irá te ajudar. Boa sorte.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    cout << "> ";
    narracao = u8"Você recebeu um saco com 3 pequenos frascos vermelhos borbulhantes.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> ";
    narracao = u8"3 Frascos de cicatrização adicionados ao INVENTÁRIO.";
    imprimirNarracao(narracao);
    cout << endl;
    
    // aqui adicionar o item ao inventário via Tabela Hash
}

// função que executa os comandos caso o jogador decida NÃO se juntar à Têmis
void respostaCasoRecusarProposta()
{
    string narracao;
    
    limparTela();
    
    cout << "> [Têmis] - ";
    narracao = u8"Como quiser. Boa sorte na sua jornada.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << ">  ";
    narracao = u8"A pessoa misteriosa se desvanece em meio a uma fumaça na sua frente, deixando um símbolo marcado no chão.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << ">  ";
    narracao = u8"Você percebe um acúmulo de um pó cinza no local. Sua curiosidade fala mais alto. Você guarda o pó em um frasco para mais tarde.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    cout << ">  ";
    narracao = u8"1 Pote de Cinzas Espirituais adicionado ao INVENTÁRIO.";
    imprimirNarracao(narracao);
    cout << endl;
    
    // aqui adicionar o item ao inventário via Tabela Hash
}

// função que direciona a conversa do prólogo para o fluxo 1.1
void respostaCaso1o1()
{
    string narracao;
    int resposta;
    
    limparTela();
    
    cout << "> [Têmis] - ";
    narracao = u8"Receio que temos um interesse em comum. Parti de minha vila há um tempo para descobrir o que são os acontecimentos recentes.";
    imprimirNarracao(narracao);
    cout << endl;
    
    while(true)
    {
        cout << "> [Têmis] - ";
        narracao = u8"Imagino que queira se juntar a mim para descobrir o que está havendo, o que acha? Podemos decifrar juntos o que as pessoas têm chamado de \"Apocalipse\".";
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
            cout << "Resposta indisponível... Vamos tentar de novo!" << flush;
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
        narracao = u8"Me encontro em um momento de muita descoberta dos mistérios recentes. Talvez essas armas que carrega podem ser úteis. O que acha de me acompanhar?";
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
            cout << "Resposta indisponível... Vamos tentar de novo!" << flush;
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
    narracao = u8"A aurora cativa essas planícies. Acredito que queira voltar sempre que puder.";
    imprimirNarracao(narracao);
    cout << endl;
    
    cout << "> [???] - ";
    narracao = u8"Eu, a propósito, estou aqui em busca de algo. Prazer, me chamo Têmis.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    cout << "> ";
    narracao = u8"O ser misterioso retira o capuz de cor marrom, revelando um rosto de uma mulher cansada, como quem já viu coisas demais.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;
    
    esperarTeclaParaContinuar();
    
    while(true)
    {
        limparTela();
    
        cout << "> [Têmis] - ";
        narracao = u8"Acredito que tenha percebido os estranhos acontecimentos recentes. Vejo que carrega armas, para que são?";
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
            cout << "Resposta indisponível... Vamos tentar de novo!" << flush;
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
    narracao = u8"Por sorte encontrou alguém com o mesmo objetivo que você. Esses acontecimentos têm me intrigado por semanas.";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "> [???] - ";
    narracao = u8"Meu nome é Têmis, a propósito. Moro em uma vila a não muito tempo daqui. As pessoas lá não sabem mais o que fazer em relação às coisas estranhas que têm acontecido.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    cout << "> ";
    narracao = u8"O ser misterioso retira o capuz de cor marrom, revelando um rosto de uma mulher cansada, como quem já viu coisas demais.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    esperarTeclaParaContinuar();
    limparTela();

    cout << "> [Têmis] - ";
    narracao = u8"Por isso, decidi eu mesma ir atrás desse mistério. Já fiz muito progresso.";
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
            cout << "Resposta indisponível... Vamos tentar de novo!" << flush;
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
    narracao = u8"Nesse caso, meu nome também não lhe diz respeito. Trilhe seu caminho sem incômodos, mas se atente aos perigos dessa estrada. Nem tudo são rosas se visto muito de perto.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    cout << "> ";
    narracao = u8"A pessoa misteriosa se desvanece em meio a uma fumaça na sua frente, deixando um símbolo marcado no chão.";
    imprimirNarracao(narracao);
    cout << endl;
    cout << endl;

    cout << "> ";
    narracao = u8"Você percebe um acúmulo de um pó cinza no local. Sua curiosidade fala mais alto. Você guarda o pó em um frasco para mais tarde.";
    imprimirNarracao(narracao);
    cout << endl;

    cout << "> ";
    narracao = u8"1 Pote de Cinzas Espirituais adicionado ao INVENTÁRIO.";
    imprimirNarracao(narracao);
    cout << endl;

    // adicionar item ao inventario aqui
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
    narracao = u8"Durante seu caminhar através uma estreita estrada de calcário, algo chama sua atenção: um ser encapuzado.";
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

// função que inicia o jogo e executa todos os comandos para o funcionamento dele
void iniciarJogo()
{
    Personagem personagem;
    
    criarPersonagem(personagem);
    
    prologo();
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
    
    // boost::locale::generator gen;
    // locale::global(gen("pt_BR.UTF-8"));
       
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