// Algoritmo arvore rubro-negra
// Icaro Costa Pavan - 840790

#include <stdio.h>
#include <stdlib.h>

#define VERMELHO 1
#define PRETO 0

typedef struct No {
    int valor;
    int cor;
    struct No *esquerda, *direita;
	struct No *pai;
} No;

No* criarNo(int valor);
No* rotacaoEsquerda(No *raiz, No *no);
No* rotacaoDireita(No *raiz, No *no);
No* balancear(No *raiz, No *noInserido);
No* encontrarLocalInserir(No *raiz, No *novo_no);
No* inserir(No *raiz, int valor);
void imprimir(No *raiz, int nivel);

int main() {
    No *raiz = NULL;
    int opcao, valor;

    while (1) {
        printf("Escolha uma opcao:\n");
        printf("[1] Inserir valor\n[2] Exibir arvore (de lado)\n[3] Sair\nR: ");
        scanf("%i", &opcao);

        switch (opcao) {
            case 1:
                printf("\nInsira o valor: ");
                scanf("%i", &valor);
                
                raiz = inserir(raiz, valor);
                printf("\n");
                break;
            case 2:
            	if(raiz != NULL) {
                	imprimir(raiz, 1);
                	printf("\n\n");
                }
                else
                	printf("\nA arvore esta vazia.\n\n");
                	
                break;
            case 3:
                printf("\nAte mais!\n\n");
                return 0;
            default:
                printf("\nOpcao invalida.\n\n");
        }
    }
    return 0;
}

// criar um no inicialmente vermelho
No* criarNo(int valor) {
    No *no = malloc(sizeof(No));
    
    no->valor = valor;
    no->cor = VERMELHO;
    no->esquerda = no->direita = no->pai = NULL;
    
    return no;
}

// rotacao a esquerda
No* rotacaoEsquerda(No *raiz, No *no) {
    No *novoPai = no->direita;
    no->direita = novoPai->esquerda;
    
    if (novoPai->esquerda != NULL)
        novoPai->esquerda->pai = no;

    novoPai->pai = no->pai;
    
    if (no->pai == NULL)
        raiz = novoPai;
    else if (no == no->pai->esquerda)
        no->pai->esquerda = novoPai;
    else
        no->pai->direita = novoPai;

    novoPai->esquerda = no;
    no->pai = novoPai;
    
    return raiz;
}

// rotacao a direita
No* rotacaoDireita(No *raiz, No *no) {
    No *novoPai = no->esquerda;
    no->esquerda = novoPai->direita;
    
    if (novoPai->direita != NULL)
        novoPai->direita->pai = no;

    novoPai->pai = no->pai;
    
    if (no->pai == NULL)
        raiz = novoPai;
    else if (no == no->pai->direita)
        no->pai->direita = novoPai;
    else
        no->pai->esquerda = novoPai;

    novoPai->direita = no;
    no->pai = novoPai;
    
    return raiz;
}

// recolorir e rebalancear arvore
No* balancear(No *raiz, No *noInserido) {
    while (noInserido != raiz && noInserido->pai->cor == VERMELHO) {
        if (noInserido->pai == noInserido->pai->pai->esquerda) {
            No *tio = noInserido->pai->pai->direita;

            // tio vermelho: tio fica preto, pai fica preto e avo fica vermelho
            if (tio != NULL && tio->cor == VERMELHO) {
                noInserido->pai->cor = PRETO;
                tio->cor = PRETO;
                noInserido->pai->pai->cor = VERMELHO;
                noInserido = noInserido->pai->pai;
            }
            else {
                // o no inserido é filho direito, rotacao a esquerda no pai
                if (noInserido == noInserido->pai->direita) {
                    noInserido = noInserido->pai;
                    raiz = rotacaoEsquerda(raiz, noInserido);
                }
                
                // o no inserido é filho esquerdo, rotacao a direita no avô
                noInserido->pai->cor = PRETO;
                noInserido->pai->pai->cor = VERMELHO;
                raiz = rotacaoDireita(raiz, noInserido->pai->pai);
            }
        }
        else {
            // pai filho direito do avo
            No *tio = noInserido->pai->pai->esquerda;

            // tio vermelho: tio fica preto, pai fica preto e avo fica vermelho
            if (tio != NULL && tio->cor == VERMELHO) {
                noInserido->pai->cor = PRETO;
                tio->cor = PRETO;
                noInserido->pai->pai->cor = VERMELHO;
                noInserido = noInserido->pai->pai;
            }
            else {
                // no inserido filho esquerdo, rotacao a direita no pai
                if (noInserido == noInserido->pai->esquerda) {
                    noInserido = noInserido->pai;
                    raiz = rotacaoDireita(raiz, noInserido);
                }
                
                // no inserido filho direito, rotacao a esquerda no avo
                noInserido->pai->cor = PRETO;
                noInserido->pai->pai->cor = VERMELHO;
                raiz = rotacaoEsquerda(raiz, noInserido->pai->pai);
            }
        }
    }
    
    // garante que a raiz sempre seja preta
    raiz->cor = PRETO;
    
    return raiz;
}

// inserir na arvore
No* encontrarLocalInserir(No *raiz, No *novo_no) {
    if(raiz == NULL) {
    	return novo_no;
	}
	else {
		if(novo_no->valor < raiz->valor) {
			raiz->esquerda = encontrarLocalInserir(raiz->esquerda, novo_no);
			raiz->esquerda->pai = raiz;
		}
		else if(novo_no->valor > raiz->valor) {
			raiz->direita = encontrarLocalInserir(raiz->direita, novo_no);
			raiz->direita->pai = raiz;
		}
		else {
			printf("\nErro: o valor ja foi inserido na arvore.\n");
			free(novo_no);
		}
	}
    
    return raiz;
}

// chamar a funcao de inserir e balancear
No* inserir(No *raiz, int valor) {
	No *novo_no = criarNo(valor);
	
	raiz = encontrarLocalInserir(raiz, novo_no);
	
	// realiza o balanceamento apenas se o no foi inserido na arvore
	if(novo_no->pai != NULL || raiz == novo_no)
		raiz = balancear(raiz, novo_no);
	
	return raiz;
}

// imprimir arvore deitada
void imprimir(No *raiz, int nivel) {
    int i;
    
    if(raiz != NULL) {
        imprimir(raiz->direita, nivel + 1);
        
        printf("\n");
        
        for (i = 0; i < nivel; i++)
            printf("\t");
        
        printf("%2i (%s)", raiz->valor, (raiz->cor == VERMELHO)? "V": "P");
        imprimir(raiz->esquerda, nivel + 1);
    }
}
