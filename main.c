#include <stdio.h>

void fibonacci(int n)
{
    // Criando vetor com N posições solicitado pelo usuário, e variável de iteração "i"
    double vetor[n];
    /*
        É utilizado double devido ao tamanho de 64bits, 
        como termos do fibonacci superam 32bits tal tipo possibilita 
        trabalharmos com números menores e maiores do que o tipo int
    */
    int i = 0;

    for (i; i < n; i++)
    {
        /*
            Uso de ternários para inicializar as primeiras posições com 0 e 1 respectivamente,
            as demais posições são preenchidas baseadas na soma dos dois últimos termos.
        */
        vetor[i] = i == 0 ? 0 : i == 1 ? 1
                                       : vetor[i - 1] + vetor[i - 2];
        // Exibindo o valor do item atual do vetor sem casas decimais
        printf("%.0f ", vetor[i]);
    }
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

    switch (escolha)
    {
    case 1:
        // Inicializando variável do número de termos da sequência de Fibonacci
        int n;

        // Registrando valor na variável baseado na entrada do usuário
        printf("Digite a quantidade de termos da sequência de Fibonacci (1 a 50): ");
        scanf(" %i", &n);

        // Validando se o valor digitado está dentro do esperado
        while (n > 50 || n < 1)
        {
            printf("Valor inválido!A quantidade de termos da sequência de Fibonacci deve ser de 1 até 50: ");
            scanf(" %i", &n);
        }

        // Chamando a função que exibe os N termos da sequência de Fibonacci
        fibonacci(n);
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
