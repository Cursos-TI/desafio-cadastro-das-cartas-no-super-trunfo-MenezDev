#include <stdio.h> //Biblioteca para entrada e saída de dados.
#include <string.h> //Biblioteca necessária para usar o strcspn().

//Desafio: Nível Mestre
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
    unsigned long int populacao1, populacao2; //Como solicitado no enunciado
    int qntdPontosTuristicos1, qntdPontosTuristicos2;
    float area1, area2, pib1, pib2, densidadePopulacional1, densidadePopulacional2;
    float inversoDensidade1, inversoDensidade2, pibPerCapita1, pibPerCapita2, superPoder1, superPoder2;

    //Variáveis de comparação

    int resultPopulacao, resultArea, resultPib, resultPontosTuristicos, resultDensidade, resultPibPerCapita, resultSuperPoder;

    //Introdução

    printf("Bem-vindo(a), por favor insira os dados das suas cartas aqui:\n");

    //Interface para entrada de dados da carta 1:
    printf("\nCarta 1:\n");

    printf("Estado (uma letra de 'A' a 'H'): ");
    scanf("%c", &estado1);
    printf("Código da Carta(letra do Estado + um número de 01 a 04): ");
    scanf("%s", codigo_carta1);

    limpar_entrada();

    printf("Nome da cidade: ");
    fgets(nomeCidade1, 50, stdin); //Lê até a quebra de linha ou o limite de caracteres
    nomeCidade1[strcspn(nomeCidade1, "\n")] = 0; //Remove o \n do final da string lida pelo fgets

    printf("População: ");
    scanf("%lu", &populacao1);

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

    printf("Estado(uma letra de 'A' a 'H'): ");
    scanf("%c", &estado2);

    printf("Código da Carta (letra do Estado + um número de 01 a 04): ");
    scanf("%s", codigo_carta2);

    limpar_entrada();

    printf("Nome da cidade: ");
    fgets(nomeCidade2, 50, stdin);
    nomeCidade2[strcspn(nomeCidade2, "\n")] = 0;

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (em km², use ponto como separador decimal - ex: 1521.11): ");
    scanf("%f", &area2);

    limpar_entrada();
    printf("PIB (Informe o PIB da cidade (em bilhões de reais, ex: 699.28): ");
    scanf("%f", &pib2);

    limpar_entrada();
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &qntdPontosTuristicos2);

    //Cálculos das variáveis

    //Carta 1:

    densidadePopulacional1 = (float)populacao1 / area1; //Cálculo densidade populacional
    pib1 = pib1 * 1000000000; // Convertendo o valor digitado (em bilhões) para reais, multiplicando por 1 bilhão
    pibPerCapita1 = pib1 / populacao1; //Cálculo PIB per capita

    //Inverso da densidade:

    inversoDensidade1 = 1.0 / densidadePopulacional1;

    //Poder total da carta 1:

    superPoder1 = (float)populacao1 + area1 + pib1 + (float)qntdPontosTuristicos1 + pibPerCapita1 + inversoDensidade1;

    //Carta 2:
    
    densidadePopulacional2 = (float)populacao2 / area2;
    pib2 = pib2 * 1000000000;
    pibPerCapita2 = pib2 / populacao2;

    //Inverso da densidade

    inversoDensidade2 = 1.0 / densidadePopulacional2;

    //Poder total da carta 2:

    superPoder2 = (float)populacao2 + area2 + pib2 + (float)qntdPontosTuristicos2 + pibPerCapita2 + inversoDensidade2;

    //Comparação das cartas:
    
    char* resultado[] = {"Carta 2 venceu", "Carta 1 venceu"}; //Para exibir qual carta venceu

    resultPopulacao = populacao1 > populacao2;
    resultArea = area1 > area2;
    resultPib = pib1 > pib2;
    resultPontosTuristicos = qntdPontosTuristicos1 > qntdPontosTuristicos2;
    resultDensidade = inversoDensidade1 > inversoDensidade2;
    resultPibPerCapita = pibPerCapita1 > pibPerCapita2;
    resultSuperPoder = superPoder1 > superPoder2;



    //Painel da saída de dados:

    //Informações da carta 1:
    printf("\nInformações das cartas:\n");
    printf("Carta 1:\n");

    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo_carta1);
    printf("Nome da cidade: %s\n", nomeCidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1 / 1000000000); //Divisão do valor do pib por 1 bilhão para exibir em "bilhões de reais"

    printf("Número de Pontos Turísticos: %d\n", qntdPontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    //Informações da carta 2:
    printf("\nCarta 2:\n");

    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo_carta2);
    printf("Nome da cidade: %s\n", nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2 / 1000000000);
    printf("Número de Pontos Turísticos: %d\n", qntdPontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    //Batalha das Cartas:

    printf("\nComparação das Cartas:\n");

    printf("População: %s (%d)\n", resultado[resultPopulacao], resultPopulacao);
    printf("Área: %s (%d)\n", resultado[resultArea], resultArea);
    printf("PIB: %s (%d)\n", resultado[resultPib], resultPib);
    printf("Pontos Turísticos: %s (%d)\n", resultado[resultPontosTuristicos], resultPontosTuristicos);
    printf("Densidade Populacional: %s (%d)\n", resultado[resultDensidade], resultDensidade);
    printf("PIB per Capita: %s (%d)\n", resultado[resultPibPerCapita], resultPibPerCapita);
    printf("Super Poder: %s (%d)\n", resultado[resultSuperPoder], resultSuperPoder);

    return 0;
}