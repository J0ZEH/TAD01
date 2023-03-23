/* Trabalho de Implementação 01 - José Florêncio e Vinicius Cerveira
   Estrutura de Dados I - Prof. Anselmo Paiva                     */

#include <stdio.h>
#include <stdlib.h>

float *produto_matriz(); //função de AxB

float *transposta_matriz(); //função da transposta

int main()
{
    int contador = 1;
    int i, j, k;
    int linhaA, colunaA, linhaB, colunaB, resposta;
    float *matrizA = NULL, *matrizB = NULL, *matriz_resposta, *matriz_transposta;

    do{

    printf("\n\n ~~~ MENU PRINCIPAL ~~~ \n");
    printf("\n1) Ler a MATRIZ A\n2) Ler a MATRIZ B\n3) Multiplicar a MATRIZ A pela MATRIZ B\n4) Calcular a Transposta da MATRIZ A\n5) Multiplicar a MATRIZ A pela Transposta da MATRIZ B\n\n");
    scanf("%d", &resposta);
    printf("\n");


    switch (resposta){

    case 1: //ler a matriz A

        printf("\nInsira o numero de linhas da Matriz A:\n");
        scanf("%d", &linhaA);
        printf("\nInsira o numero de colunas da Matriz A:\n");
        scanf("%d", &colunaA);

        matrizA = (float*)malloc(sizeof(float)*linhaA*colunaA);
        for (i = 0; i < linhaA; i++){
            for (j = 0; j < colunaA; j++){
                printf("\nDigite o numero da posicao [%d][%d]:", i, j);
                scanf("%f", &matrizA[colunaA*i+j]);
            }
        }
        break;

    case 2: //ler a matriz B

        printf("\nInsira o numero de linhas da Matriz B:\n");
        scanf("%d", &linhaB);
        printf("\nInsira o numero de colunas da Matriz B:\n");
        scanf("%d", &colunaB);

        matrizB = (float*)malloc(sizeof(float)*linhaB*colunaB);
        for (i = 0; i < linhaB; i++){
            for (j = 0; j < colunaB; j++){
                printf("\nDigite o numero da posicao [%d][%d]:", i, j);
                scanf("%f", &matrizB[colunaB*i+j]);
            }
        }
        break;

    case 3: //multiplicacao AxB

        if (matrizA != NULL && matrizB != NULL){
            if (colunaA == linhaB){ //condicao da possibilidade de multiplicacao
                matriz_resposta = produto_matriz(matrizA, matrizB, linhaA, colunaA, linhaB, colunaB);
                if (matriz_resposta == NULL){
                    printf("\nErro nos parametros.\n");
                    break;
                }
                for (i = 0; i < linhaA; i++){
                    for (j = 0; j < colunaB; j++){
                        printf("%.2f\t ", matriz_resposta[colunaB*i+j]);
                    }
                    printf("\n");
                }
            }else{
                printf("\nColunas de A diferente de Linhas de B. Nao e' possivel multiplicar\n");
            }
        }else{
            printf("\nA matriz A e/ou a Matriz B nao possui(em) valor(es) validos.\n");
        }
        break;

    case 4: //transposta de A

        if (matrizA != NULL){

            matriz_resposta = transposta_matriz(matrizA, linhaA, colunaA);
            if (matriz_resposta == NULL){
                printf("\nErro nos parametros\n");
                break;
            }

            for (i = 0; i < colunaA ; i++){
                for (j = 0; j < linhaA; j++){
                    printf("%.2f\t ", matriz_resposta[linhaA*i+j]);
                }
                printf("\n");
            }
        }else{
            printf("\nInsira um valor valido para a matriz A.");
        }
        break;

    case 5: //Matriz A pela transposta de B

        if (matrizA != NULL && matrizB != NULL){
            if (colunaA == colunaB){
                matriz_transposta = transposta_matriz(matrizB, linhaB, colunaB);
                matriz_resposta = produto_matriz(matrizA, matriz_transposta, linhaA, colunaA, colunaB, linhaB);
                if (matriz_resposta == NULL){
                    printf("\nErro nos parametros.\n");
                    break;
                }
                for (i = 0; i < linhaA; i++){
                    for (j = 0; j < linhaB; j++){
                        printf("%.2f\t ", matriz_resposta[linhaB*i+j]);
                    }
                    printf("\n");
                }
            }
            else{
                printf("\nColunas de A e' diferente de Linhas da transposta de B. Nao e possivel multiplicar.\n");
            }
        }else{
            printf("\nA matriz A e/ou a matriz B nao possui(em) valor(es) validos.\n");
        }
        break;

    default:
        printf("\nDigite uma opcao valida.\n");
        break;

        }//fim do switch

    }while (contador == 1);


    return 0;
}

//função produto_matriz

float *produto_matriz(float *MatrizA, float *MatrizB, int linhaA, int colunaA, int linhaB, int colunaB){

    int i, j, k; //contadores

    if (MatrizA != NULL && MatrizB != NULL){
        if (linhaA > 0 && linhaB > 0 && colunaA > 0 && colunaB >0){
            float *matrizAB = (float*)malloc(sizeof(float) *linhaA *colunaB);
            if (matrizAB != NULL){
                for (i = 0; i < linhaA; i++){
                    for (j = 0; j < colunaB; j++){
                        matrizAB[i*colunaB+j] = 0;
                        for (k = 0; k < colunaA; k++){
                            matrizAB[i*colunaB+j] += MatrizA[i*colunaA+k]*MatrizB[k*colunaB+j];
                        }
                    }
                }
                return matrizAB;
            }
        }
    }



}

//função transposta_matriz

float *transposta_matriz(float *matriz, int linha, int coluna){ 

    int i, j; 

    if (matriz != NULL){
        if (linha > 0 && coluna > 0){ //
            float *mat_transposta = (float*)malloc(sizeof(float) *linha *coluna); //
            if (mat_transposta != NULL){ //
                for (i = 0; i < linha; i++){ //
                    for (j = 0; j < coluna; j++){ // 
                        mat_transposta[j*linha+i] = matriz[i*coluna+j]; //
                    }
                }
                return mat_transposta; //
            }
        }
    }

}
