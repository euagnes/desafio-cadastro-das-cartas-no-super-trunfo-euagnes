#include <stdio.h>

typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
    float super_poder;
} Carta;

void lerCarta(Carta *carta) {
    printf("Digite o estado: ");
    scanf(" %[^\n]", carta->estado);
    
    printf("Digite o código: ");
    scanf("%d", &carta->codigo);

    printf("Digite o nome: ");
    scanf(" %[^\n]", carta->nome);

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

void calcularAtributos(Carta *carta) {
    carta->densidade = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib * 1000000000 / carta->populacao;

    // Super Poder = soma dos atributos:
    // população + área + PIB + pontos turísticos + PIB per capita + inverso da densidade
    // Casts são importantes aqui para manter o tipo float
    carta->super_poder = (float)carta->populacao +
                         carta->area +
                         carta->pib +
                         (float)carta->pontos_turisticos +
                         carta->pib_per_capita +
                         (1.0f / carta->densidade);
}

void compararCartas(Carta c1, Carta c2) {
    printf("\nComparação de Cartas:\n");

    printf("População: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", c1.area > c2.area);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidade < c2.densidade);  // menor vence
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pib_per_capita > c2.pib_per_capita);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.super_poder > c2.super_poder);
}

int main() {
    Carta carta1, carta2;

    printf("Digite os dados da Carta 1:\n");
    lerCarta(&carta1);
    calcularAtributos(&carta1);

    printf("\nDigite os dados da Carta 2:\n");
    lerCarta(&carta2);
    calcularAtributos(&carta2);

    compararCartas(carta1, carta2);

    return 0;
}
