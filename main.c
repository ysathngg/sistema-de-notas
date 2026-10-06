#include <stdio.h>

int main() {
    float precos_encomendas[100];
    int qtd_encomendas = 0;
    int opcao_menu = 0;

    while (opcao_menu != 5) {
        printf("\n========================================\n");
        printf("    ATELIÊ YSA PERSONALIZADOS - CRUD    \n");
        printf("========================================\n");
        printf("1. Registrar valor de nova encomenda\n");
        printf("2. Consultar todas as encomendas\n");
        printf("3. Atualizar valor de encomenda\n");
        printf("4. Cancelar/Remover encomenda\n");
        printf("5. Sair do sistema\n");
        printf("----------------------------------------\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao_menu);

        switch (opcao_menu) {
            case 1:
                if (qtd_encomendas < 100) {
                    printf("\n[NOVA ENCOMENDA]\n");
                    printf("Informe o valor do item personalizado (R$): ");
                    scanf("%f", &precos_encomendas[qtd_encomendas]);
                    
                    if (precos_encomendas[qtd_encomendas] > 0) {
                        qtd_encomendas++;
                        printf(">> Encomenda registrada com sucesso no Ysa Personalizados!\n");
                    } else {
                        printf(">> Atencao: O valor precisa ser maior que R$ 0.00.\n");
                    }
                } else {
                    printf(">> Capacidade maxima de 100 encomendas atingida!\n");
                }
                break;

            case 2:
                if (qtd_encomendas == 0) {
                    printf("\n>> Nenhuma encomenda registrada no momento.\n");
                } else {
                    printf("\n========================================\n");
                    printf("       ENCOMENDAS REGISTRADAS           \n");
                    printf("========================================\n");
                    int i = 0;
                    while (i < qtd_encomendas) {
                        printf("ID %d | Valor: R$ %.2f\n", i, precos_encomendas[i]);
                        i++;
                    }
                }
                break;

            case 3:
                if (qtd_encomendas == 0) {
                    printf("\n>> Nao ha encomendas para atualizar.\n");
                } else {
                    int id_busca;
                    printf("\n[ATUALIZAR VALOR]\n");
                    printf("Digite o ID da encomenda que deseja alterar: ");
                    scanf("%d", &id_busca);

                    if (id_busca >= 0 && id_busca < qtd_encomendas) {
                        printf("Digite o novo valor para a encomenda ID %d: R$ ", id_busca);
                        scanf("%f", &precos_encomendas[id_busca]);
                        printf(">> Valor da encomenda atualizado com sucesso!\n");
                    } else {
                        printf(">> Erro: ID de encomenda nao encontrado.\n");
                    }
                }
                break;

            case 4:
                if (qtd_encomendas == 0) {
                    printf("\n>> Nao ha encomendas para remover.\n");
                } else {
                    int id_busca;
                    printf("\n[REMOVER ENCOMENDA]\n");
                    printf("Digite o ID da encomenda que deseja cancelar: ");
                    scanf("%d", &id_busca);

                    if (id_busca >= 0 && id_busca < qtd_encomendas) {
                        int i = id_busca;
                        while (i < qtd_encomendas - 1) {
                            precos_encomendas[i] = precos_encomendas[i + 1];
                            i++;
                        }
                        qtd_encomendas--;
                        printf(">> Encomenda ID %d removida do sistema.\n", id_busca);
                    } else {
                        printf(">> Erro: ID de encomenda nao encontrado.\n");
                    }
                }
                break;

            case 5:
                printf("\nEncerrando o sistema do Atelie Ysa Personalizados... Ate breve!\n");
                break;

            default:
                printf("\n>> Opcao invalida! Escolha um numero de 1 a 5.\n");
                break;
        }
    }

    return 0;
}
    
