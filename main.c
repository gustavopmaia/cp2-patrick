#include <stdio.h>

int fibonacci() 
{
}

int fatorial()
{
}

int palindromo()
{
}

int substring()
{
    char frase[100];
    char palavra[100];
    
    printf("Qual a frase que quer procurar? ");
    gets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = 0;

    printf("\nQual a palavra que está procurando? ");
    scanf("\n %s", &palavra);
    palavra[strcspn(palavra, "\n")] = 0;
    
    printf("\nFrase: %s", frase);
    printf("\nPalavra: %s", palavra);
}

int main()
{
    int escolha;
    
    printf("====== MENU DE EXERCÍCIOS ======\n");
    printf("1 - Sequência de Fibonacci;\n");
    printf("2 - Fatoriais;\n");
    printf("3 - Verificar Palíndromo;\n");
    printf("4 - Verificar Substring.\n");
    printf("0 - Sair.\n");
    printf("Selecione uma opção: ");
    scanf("%d", &escolha);
        
    switch (escolha) {
        case 1:
            fibonacci();
            break;
        case 2:
            fatorial();
            break;
        case 3:
            palindromo();
            break;
        case 4:
            substring();
            break;
        case 0:
            printf("Saindo do programa\n");
            return 0;
        default:
            printf("Opção inválida! Tente novamente.\n");
    }
}
