#include <stdio.h>
#include <stdlib.h>

// Funções para operações aritméticas
float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { return a / b; }

// Função para converter um número de uma base para decimal
long long convertToDecimal(char *numStr, int baseFrom) {
    return strtoll(numStr, NULL, baseFrom);
}

// Função para converter um número decimal para outra base
void convertFromDecimal(long long num, int baseTo) {
    char convertedNum[50];
    ldiv_t division;

    int index = 0;
    while (num > 0) {
        division = ldiv(num, baseTo);
        if (division.rem < 10)
            convertedNum[index] = '0' + division.rem;
        else
            convertedNum[index] = 'A' + division.rem - 10;

        num = division.quot;
        index++;
    }

    printf("Número convertido para base %d: ", baseTo);
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", convertedNum[i]);
    }
    printf("\n");
}

int main() {
    char numStr[50];
    int choice, baseFrom, baseTo;
    float num1, num2, result;

    while (1) {
        printf("Selecione a operação:\n");
        printf("1. Operações aritméticas\n");
        printf("2. Conversão de bases numéricas\n");
        printf("3. Sair\n");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Encerrando a calculadora...\n");
            break;
        }

        if (choice == 1) {
            printf("\nDigite dois números: ");
            scanf("%f %f", &num1, &num2);

            while (1) {
                printf("\nSelecione a operação:\n");
                printf("1. Adição\n");
                printf("2. Subtração\n");
                printf("3. Multiplicação\n");
                printf("4. Divisão\n");
                printf("5. Voltar ao menu anterior\n");
                scanf("%d", &choice);

                if (choice == 5) {
                    break; // Volta ao menu anterior
                }
                    switch (choice) {
                    case 1:
                        result = add(num1, num2);
                        break;
                    case 2:
                        result = subtract(num1, num2);
                        break;
                    case 3:
                        result = multiply(num1, num2);
                        break;
                    case 4:
                        if (num2 != 0)
                            result = divide(num1, num2);
                        else {
                            printf("Não é possível dividir por zero.\n");
                            continue;
                        }
                        break;
                    default:
                        printf("Operação inválida.\n");
                        continue;
                }

                printf("Resultado: %.2f\n", result);

            }
        } else if (choice == 2) {
            while (1) {
                printf("\nSelecione a conversão de base numérica:\n");
                printf("1. Decimal para Binário\n");
                printf("2. Decimal para Octal\n");
                printf("3. Decimal para Hexadecimal\n");
                printf("4. Binário para Decimal\n");
                printf("5. Octal para Decimal\n");
                printf("6. Hexadecimal para Decimal\n");
                printf("7. Voltar ao menu anterior\n");
                scanf("%d", &choice);

                if (choice == 7) {
                    break; // Volta ao menu anterior
                }

                if (choice >= 1 && choice <= 6) {
                    printf("\nDigite o número: ");
                    scanf("%s", numStr);

                    switch (choice) {
                        case 1:
                            convertFromDecimal(convertToDecimal(numStr, 10), 2);
                            break;
                        case 2:
                            convertFromDecimal(convertToDecimal(numStr, 10), 8);
                            break;
                        case 3:
                            convertFromDecimal(convertToDecimal(numStr, 10), 16);
                            break;
                        case 4:
                            printf("Número decimal: %lld\n", convertToDecimal(numStr, 2));
                            break;
                        case 5:
                            printf("Número decimal: %lld\n", convertToDecimal(numStr, 8));
                            break;
                        case 6:
                            printf("Número decimal: %lld\n", convertToDecimal(numStr, 16));
                            break;
                    }
                } else {
                    printf("Opção inválida. Por favor, selecione uma opção válida.\n");
                }
            }
        } else {
            printf("Opção inválida. Por favor, selecione uma opção válida.\n");
        }
    }

    return 0;
}
