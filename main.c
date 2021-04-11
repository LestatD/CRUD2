#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define TAMANHO 10             //Declaração de constante, pode ser alterado conforme a necessidade do usuário de armazenar mais cartas.

typedef struct

{
    char artista[50];          // Recebe o nome do artista da gravura usada.
    char caixa_de_texto[500];  // Recebe a descricao das habilidades da carta.
    char cor[50];              // Recebe o nome da cor que a carta representa.
    char formatos_validos[50]; // Recebe a descricao de quais formatos de jogo a carta pode ser usada.
    char linha_de_tipo[50];    // Recebe o tipo da carta.
    char subtipo[50];          // Recebe o subtipo da carta.
    char titulo[50];           // Recebe o nome da carta.
    char custo_de_mana[50];    // Recebe o custo para conjurar a mágica.
    char ed_numero[50];        // Recebe o nome da edição e o número que a carta representa na coleção.
    char poder[50];            // Recebe o valor da quantidade de dano que a criatura causar em combate.
    char resistencia[50];      // Recebe o valor da quantidade de dano que ela tem que sofrer em um único turno para ser destruída.
    char preco_medio[50];      // Recebe o valor do preço médio em reais qua a carta custa.
    char raridade[50];         // Recebe a indicacao de qual a raridade da carta.

    int ativo;

}Carta;

Carta carta[TAMANHO];

int opcao;                     //Variável usada para escolha de opções do usuário.
int armazenamento;


void cadastro();               //Códigos da parte de cadastro.
void menu();                   //Códigos da parte de pesquisa.
void lista();                  //Códigos da parte de lista.
void editar();                 //Códigos da parte de edição de dados.

int main(int argc, char const *argv[])
{

    setlocale(LC_ALL, "Portuguese");    //Para usar caracteres da lingua portuguesa.
    menu();
    return 0;
}

void menu()                     //Menu Principal.
{

    do
    {
        system("cls");      //Como o programa mostra muitos textos, achei melhor limpar a tela frequentemente para ficar mais organizado.

        printf("  --------------------------------------------------------------------------- \n");
        printf(" |             Menu de Cadastro de Cartas de Magic The Gathering             |\n");
        printf("  --------------------------------------------------------------------------- \n\n");

        //Opções principais do programa para escolha do usuário.

        printf("1 - Cadastrar nova carta\n");
        printf("2 - Listar todas as cartas cadastradas\n");
        printf("3 - Editar carta\n");
        printf("0 - Sair\n");
        printf("\nSelecione uma das opções: ");
        scanf("%d", &opcao);

        getchar();

        switch (opcao)
        {
            case 0:
                break;
            case 1:
                cadastro();     //Entra da função de Cadastro.
                break;
            case 2:
                lista();        //Entra da função de Lista.
                break;
            case 3:
                editar();       //Entra da função de Editar.
                break;

            default:
                printf("Número inválido. Por favor, escolha uma opção de 0 a 3.\n");         //Mensagem informativa, usuário digita um número de 0 a 3.
                break;
        }
        getchar();
    }
    while (opcao != 0);
}

void cadastro()
{
    char artista[50];
    char caixa_de_texto[500];
    char cor[50];
    char formatos_validos[50];
    char linha_de_tipo[50];
    char subtipo[50];
    char titulo[50];
    char custo_de_mana[50];
    char ed_numero[50];
    char poder[50];
    char resistencia[50];
    char preco_medio[50];
    char raridade[50];

    int opcao;



    do{
        system("cls");
        fflush(stdin);


        printf("\nDigite o nome da carta: ");
        gets(titulo);

        printf("\nDigite o texto da carta: ");
        gets(caixa_de_texto);

        printf("\nDigite a cor da carta: ");
        gets(cor);

        printf("\nDigite o tipo da carta: ");
        gets(linha_de_tipo);

        printf("\nDigite o subtipo da carta: ");
        gets(subtipo);

        printf("\nDigite a raridade da carta: ");
        gets(raridade);

        printf("\nDigite o número referente ao poder da carta: ");
        gets(poder);

        printf("\nDigite o número referente a resistência da carta: ");
        gets(resistencia);

        printf("\nDigite o custo de mana da carta: ");
        gets(custo_de_mana);

        printf("\nDigite os formatos válidos da carta: ");
        gets(formatos_validos);

        printf("\nDigite o nome do artista da carta: ");
        gets(artista);

        printf("\nDigite o nome da edição e o número da carta: ");
        gets(ed_numero);

        printf("\nDigite o preço médio da carta R$: ");
        gets(preco_medio);

        for (int i = 0; i < TAMANHO; ++i)
        {
            if (carta[i].ativo==0)
            {
                printf("\nCarta cadastrada na posição: %d\n", i+1);

                strcpy(carta[i].titulo, titulo);
                strcpy(carta[i].caixa_de_texto, caixa_de_texto);
                strcpy(carta[i].cor, cor);
                strcpy(carta[i].linha_de_tipo, linha_de_tipo);
                strcpy(carta[i].subtipo, subtipo);
                strcpy(carta[i].raridade, raridade);
                strcpy(carta[i].custo_de_mana, custo_de_mana);
                strcpy(carta[i].formatos_validos, formatos_validos);
                strcpy(carta[i].artista, artista);
                strcpy(carta[i].ed_numero, ed_numero);
                strcpy(carta[i].poder, poder);
                strcpy(carta[i].resistencia, resistencia);
                strcpy(carta[i].preco_medio, preco_medio);
                carta[i].ativo=1;
                break;
            }
        }
        printf("\n1 - Continuar cadastrando\n0 - Voltar ao menu principal\n");
        scanf("%d", &opcao);
    }while(opcao!=0);
}

void lista()
{

    system("cls");
    fflush(stdin);
    printf("\nLista de cartas cadastradas: \n\n");

    for (int i = 0; i < TAMANHO; i++)
    {
        if (carta[i].ativo==1)
        {
            printf("\nPosição de cadastro: %d\n\n", i+1);
            printf("Nome: %s\n", carta[i].titulo);
            printf("texto: %s\n", carta[i].caixa_de_texto);
            printf("Cor: %s\n", carta[i].cor);
            printf("Tipo: %s\n", carta[i].linha_de_tipo);
            printf("Subtipo: %s\n", carta[i].subtipo);
            printf("Raridade: %s\n", carta[i].raridade);
            printf("Poder: %s\n", carta[i].poder);
            printf("Resistencia: %s\n", carta[i].resistencia);
            printf("Custo: %s\n", carta[i].custo_de_mana);
            printf("Formato: %s\n", carta[i].formatos_validos);
            printf("Artista: %s\n", carta[i].artista);
            printf("Edicao e numero: %s\n", carta[i].ed_numero);
            printf("Preço: %s\n\n", carta[i].preco_medio);
        }
        else
        {
            printf("\nNão há mais cartas cadastradas na base de dados.\n");
            break;
        }
    }
    getchar();
}
void editar()
{
    system("cls");
    fflush(stdin);

    int i;

    printf("\nDigite o número da posição da carta que você deseja substituir os dados armazendos.\n");
    printf("Obs. Verificar a posição de cada carta já armazenada na opção 'lista' do menu principal\n\n");
    scanf("%d", &i);
    i--;

    if(carta[i].ativo==1)
    {

        fflush(stdin);

        printf("\nDigite o nome da nova carta: ");
        gets(carta[i].titulo);

        printf("\nDigite o texto da nova carta: ");
        gets(carta[i].caixa_de_texto);

        printf("\nDigite a cor da nova carta: ");
        gets(carta[i].cor);

        printf("\nDigite o tipo da nova carta: ");
        gets(carta[i].linha_de_tipo);

        printf("\nDigite o subtipo da nova carta: ");
        gets(carta[i].subtipo);

        printf("\nDigite a raridade da nova carta: ");
        gets(carta[i].raridade);

        printf("\nDigite o número referente ao poder da nova carta: ");
        gets(carta[i].poder);

        printf("\nDigite o número referente a resistência da nova carta: ");
        gets(carta[i].resistencia);

        printf("\nDigite o custo de mana da nova carta: ");
        gets(carta[i].custo_de_mana);

        printf("\nDigite os formatos válidos da nova carta: ");
        gets(carta[i].formatos_validos);

        printf("\nDigite o nome do artista da nova carta: ");
        gets(carta[i].artista);

        printf("\nDigite o nome da edição e o número da nova carta: ");
        gets(carta[i].ed_numero);

        printf("\nDigite o preço médio da nova carta R$: ");
        gets(carta[i].preco_medio);

        printf("\nA nova carta foi armazenada na posição %d.\n", i+1);

        getchar();

    }
    else
    {              //Caso não exista carta cadastrada na posição digitada, segue uma mensagem informando como proceder.
        printf("\n\nNão existe carta cadastrada na posição %d. Por favor verifique o valor correto e tente novamente.\n",i+1);
        getchar();
        getchar();
    }
}
