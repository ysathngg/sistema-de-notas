#include 

int main() {
    float notas[100]; // Vetor para armazenar ate 100 notas
    int total_notas = 0;
    int opcao = 0;

    while (opcao != 5) {
        printf("\n--- MENU DE NOTAS (CRUD) ---\n");
        printf("1 - Cadastrar nota\n");
        printf("2 - Listar notas\n");
        printf("3 - Modificar nota\n");
        printf("4 - Excluir nota\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (total_notas < 100) {
                    printf("Digite a nota (0 a 10): ");
                    scanf("%f", &notas[total_notas]);
                    if (notas[total_notas] >= 0 && notas[total_notas] <= 10) {
                        total_notas++;
                        printf("Nota cadastrada com sucesso!\n");
                    } else {
                        printf("Nota invalida! Deve ser entre 0 e 10.\n");
                    }
                } else {
                    printf("Limite de notas atingido!\n");
                }
                break;

            case 2:
                if (total_notas == 0) {
                    printf("Nenhuma nota cadastrada ate o momento.\n");
                } else {
                    printf("\n--- LISTA DE NOTAS ---\n");
                    int i = 0;
                    while (i < total_notas) {
                        printf("Indice %d: Nota = %.2f\n", i, notas[i]);
                        i++;
                    }
                }
                break;

            case 3:
                if (total_notas == 0) {
                    printf("Nenhuma nota para modificar.\n");
                } else {
                    int indice;
                    printf("Digite o indice da nota que deseja modificar: ");
                    scanf("%d", &indice);

                    if (indice >= 0 && indice < total_notas) {
                        printf("Digite a nova nota: ");
                        scanf("%f", &notas[indice]);
                        printf("Nota modificada com sucesso!\n");
                    } else {
                        printf("Indice nao encontrado!\n");
                    }
                }
                break;

            case 4:
                if (total_notas == 0) {
                    printf("Nenhuma nota para excluir.\n");
                } else {
                    int indice;
                    printf("Digite o indice da nota que deseja excluir: ");
                    scanf("%d", &indice);

                    if (indice >= 0 && indice < total_notas) {
                        int i = indice;
                        while (i < total_notas - 1) {
                            notas[i] = notas[i + 1];
                            i++;
                        }
                        total_notas--;
                        printf("Nota excluida com sucesso!\n");
                    } else {
                        printf("Indice nao encontrado!\n");
                    }
                }
                break;

            case 5:
                printf("Saindo do programa... Ate mais!\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    }

    return 0;
}
