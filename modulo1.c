#include <stdio.h>

// Estrutura para representar uma cidade
typedef struct {
    char estado;
    char nome[50];
    char codigo[5];
    unsigned long int populacao;
    double area;
    double pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular a densidade populacional e PIB per capita
void calcularDados(Carta *carta) {
    carta->densidade_populacional = (float)carta->populacao / carta->area;
    carta->pib_per_capita = (float)carta->pib / carta->populacao;
    carta->super_poder = carta->populacao + carta->area + carta->pib + carta->pontos_turisticos + carta->pib_per_capita + (1 / carta->densidade_populacional);
}

// Função para obter entrada do usuário
void lerCarta(Carta *carta) {
    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &carta->estado);
    getchar();
    printf("Digite o nome da cidade: ");
    scanf(" %[^]", carta->nome);
    printf("Digite o código da carta (ex: A01, A02, B01): ");
    scanf("%s", carta->codigo);
    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);
    printf("Digite a área: ");
    scanf("%lf", &carta->area);
    printf("Digite o PIB: ");
    scanf("%lf", &carta->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
    calcularDados(carta);
}

// Função para comparar os atributos das cartas
void compararCartas(Carta c1, Carta c2) {
    printf("\nComparação de Cartas:\n");
    printf("População: %d\n", c1.populacao > c2.populacao);
    printf("Área: %d\n", c1.area > c2.area);
    printf("PIB: %d\n", c1.pib > c2.pib);
    printf("Pontos Turísticos: %d\n", c1.pontos_turisticos > c2.pontos_turisticos);
    printf("Densidade Populacional: %d\n", c1.densidade_populacional < c2.densidade_populacional);
    printf("PIB per Capita: %d\n", c1.pib_per_capita > c2.pib_per_capita);
    printf("Super Poder: %d\n", c1.super_poder > c2.super_poder);
}

int main() {
    Carta carta1, carta2;
    
    printf("Cadastro da Carta 1:\n");
    lerCarta(&carta1);
    printf("Cadastro da Carta 2:\n");
    lerCarta(&carta2);

    compararCartas(carta1, carta2);
    
    return 0;
}