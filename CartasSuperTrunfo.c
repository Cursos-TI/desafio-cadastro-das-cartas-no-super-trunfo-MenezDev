#include <stdio.h> //Biblioteca para entrada e saída de dados.
#include <string.h> //Biblioteca necessária para usar o strcspn().

//Desafio: Nível Aventureiro
//Super Trunfo - Países


//função para limpar o buffer de entrada
void limpar_entrada() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF){}
}

int main()
{
   
    //Declaração das variáveis:
    char estado1, estado2;
    char codigo_carta1[10], codigo_carta2[10], nomeCidade1[50], nomeCidade2[50];
    int populacao1, populacao2, qntdPontosTuristicos1, qntdPontosTuristicos2;
    float area1, area2, pib1, pib2, densidadePopulacional1, densidadePopulacional2, pibPerCapita1, pibPerCapita2;

    printf("Bem-vindo(a), por favor insira os dados das suas cartas aqui:\n");

    //Interface para entrada de dados da carta 1:
    printf("\nCarta 1:\n");

    printf("Estado (uma letra de 'A' a 'H'): ");
    scanf("%c", &estado1);
    printf("Código da Carta (letra do Estado + um número de 01 a 04): ");
    scanf("%s", codigo_carta1);

    limpar_entrada();

    printf("Nome da cidade: ");
    fgets(nomeCidade1, 50, stdin); //Lê até a quebra de linha ou o limite de caracteres
    nomeCidade1[strcspn(nomeCidade1, "\n")] = 0; //remove o \n do final da string lida pelo fgets

    printf("População: ");
    scanf("%d", &populacao1);

    printf("Área (em km², use ponto como separador decimal - ex: 1521.11): ");
    scanf("%f", &area1);

    limpar_entrada();

    printf("PIB (informe o PIB da cidade (em bilhões de reais, ex: 699.28): ");
    scanf("%f", &pib1);

    limpar_entrada();

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &qntdPontosTuristicos1);

    //Interface para entrada de dados da carta 2:
    printf("\nCarta 2:\n");

    limpar_entrada();

    printf("Estado (uma letra de 'A' a 'H'): ");
    scanf("%c", &estado2);

    printf("Código da Carta (letra do Estado + um número de 01 a 04): ");
    scanf("%s", codigo_carta2);

    limpar_entrada();

    printf("Nome da cidade: ");
    fgets(nomeCidade2, 50, stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = 0;

    printf("População: ");
    scanf("%d", &populacao2);

    printf("Área (em km², use ponto como separador decimal - ex: 1521.11): ");
    scanf("%f", &area2);

    limpar_entrada();
    printf("PIB (informe o PIB da cidade (em bilhões de reais, ex: 699.28): ");
    scanf("%f", &pib2);

    limpar_entrada();
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &qntdPontosTuristicos2);

    //Cálculos das variáveis

    //Carta 1:

    densidadePopulacional1 = populacao1 / area1; //Cálculo densidade populacional
    pib1 = pib1 * 1000000000; // Convertendo o valor digitado (em bilhões) para reais, multiplicando por 1 bilhão
    pibPerCapita1 = pib1 / populacao1; //Cálculo PIB per capita

    //Carta 2:
    
    densidadePopulacional2 = populacao2 / area2;
    pib2 = pib2 * 1000000000;
    pibPerCapita2 = pib2 / populacao2;

    //Painel da saída de dados:

    //Informações da carta 1:
    printf("\nInformações das cartas:\n");
    printf("Carta 1:\n");

    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo_carta1);
    printf("Nome da cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1 / 1000000000); //divisão do valor do pib por 1 bilhão para exibir em "bilhões de reais"

    printf("Número de Pontos Turísticos: %d\n", qntdPontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    //Informações da carta 2:
    printf("\nCarta 2:\n");

    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo_carta2);
    printf("Nome da cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2 / 1000000000);
    printf("Número de Pontos Turísticos: %d\n", qntdPontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    return 0;
}
