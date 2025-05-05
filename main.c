#include <stdio.h>
#include <string.h>

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

// Função auxiliar para calcular o fatorial de um número
long int calcularFatorial(int numero) {
    long int fatorial = 1;
    for (int i = 1; i <= numero; i++) {
        fatorial *= i;
    }
    return fatorial;
}

// Função que exibe os fatoriais de 1 até n
int fatorial()
{
    int n;

    printf("Digite um número inteiro (1 a 20): ");
    scanf("%d", &n);

    if (n < 1 || n > 20)
    {
        printf("Por favor, insira um número entre 1 e 20.\n");
        return 1;
    }

    printf("Fatoriais:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d! = %ld\n", i, calcularFatorial(i));
    }

    return 0;
}

int palindromo()
{
    char palavra[100];
    char invertido[100];

    /*
    Início do programa
    */

    // Pega palavra do usuário
    printf("Escreva uma palavra: ");
    scanf("%s", palavra);

    // Pega tamanho de len
    int len = strlen(palavra);

    // Inverte a palavra
    for (int i = 0; i < len; i++)
    {
        invertido[i] = palavra[len - i - 1];
    }
    invertido[len] = '\0'; // Adiciona o caractere nulo ao final da string invertida

    printf("Palavra: %s\n", palavra);

    if (strcmp(palavra, invertido) == 0)
    {
        printf("A palavra é um palíndromo");
    }
    else
    {
        printf("A palavra não é um palíndromo");
    }

    return 0;
}

int substring()
{
    // Definindo dois vetores, onde vou armazenar a frase e a palavra em seus respectivos vetores
    char frase[100];
    char palavra[100];
    
    // Limpo o buffer do teclado (limpando "lixo" que possa ter ficado após um scanf ou fgets)
    getchar();

    // Pego a frase do usuário e armazeno
    printf("Qual a frase que quer procurar? ");
    fgets(frase, sizeof(frase), stdin);
    // Removendo o \n que vem quando o usuário pressiona enter
    frase[strcspn(frase, "\n")] = 0;

    // Armazeno a palavra que o usuário está procurando
    printf("Qual a palavra que está procurando? ");
    scanf("%s", palavra);
    
    // A função strstr procura se uma palavra aparece dentro de uma frase e retorna um ponteiro para aquela posição.
    if (strstr(frase, palavra) != NULL) {
        printf("A palavra \"%s\" está contida na frase \"%s\".\n", palavra, frase);
    }
    else {
        printf("A palavra \"%s\" NÃO está contida na frase \"%s\".\n", palavra, frase);
    }
    return 0;
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
