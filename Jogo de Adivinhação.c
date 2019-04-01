#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>

int main(){
    
    setlocale(LC_ALL, "Portuguese");

    // Imprime o cabeçalho jogo
    printf("\n\n                                                     \n");
    printf("   .----------------.                                    \n");
    printf("  | .--------------. |                                   \n");
    printf("  | |    ______    | |                                   \n");
    printf("  | |   / _ __ `.  | |           BEM VINDO AO            \n");
    printf("  | |  |_/____) |  | |        Jogo de Adivinhação!       \n");
    printf("  | |    /  ___.'  | |                                   \n");
    printf("  | |    |_|       | |                                   \n");
    printf("  | |    (_)       | |                                   \n");
    printf("  | |              | |                                   \n");
    printf("  | '--------------' |                                   \n");
    printf("   '----------------'                                    \n");
    printf("\n\n                                                     \n");              

    int segundos = time(0); // Dá o número randômico que queremos, pegando os segundo desde 01/01/1970 até agora.
    srand(segundos); 

    int big_num_rand = rand(); //grande número aleatório

    int num_sec = big_num_rand % 200; //num_sec é o número secreto.
    int palpite;
    int tentativa = 1;   // Quantas tentativas foram feitas
    double score = 1000; // Pontuação inicial

    int certo = 0; // Se o palpite estiver certo

    int nivel;
    printf("\nQual o nível de dificuldade?\n");
    printf("(1) Fácil\n");
    printf("(2) Médio\n");
    printf("(1) DIfícil\n\n");
    scanf("%d", &nivel);

    int tentar; //número de tentativas por nível
    switch(nivel){
        case 1:
            tentar = 20;
            break;
        case 2:
            tentar = 12;
            break;
        default:
            tentar = 6;
            break;
    }
    
    for(int i = 1; i <= tentar; i++){
        printf("\nTentativa %d:\n", tentativa);
        printf("Qual o seu palpite? ");
        scanf("%d", &palpite);
        tentativa ++;

        if(palpite < 0){
            printf("Você não pode chutar números negativos.\n");

            continue;
        }
    
        certo = (palpite == num_sec);
        int maior = palpite > num_sec;
        if(certo){ // Se o palpite estiver certo, então o programa sairá do loop e irá para o final.
            break;
        }

        else if(maior){
            printf("\nTeu chute foi maior que o número secreto.\n");
        }
        else{
            printf("\nTeu chute foi menor que o número secreto.\n");
        }
        double reduz = abs(palpite - num_sec) / (double)2; // reduz diz quanto será retirado de score, para obter-se a pontuação final do jogo.
        score = score - reduz;
    }
    printf("\n\nFim de jogo!!\n");

    if(certo){

        printf("\n\n                                                      \n");
        printf("      ░░░░░░░░░░░░░░░░░░░░░░█████████                     \n");
        printf("      ░░███████░░░░░░░░░░███▒▒▒▒▒▒▒▒███                   \n");
        printf("      ░░█▒▒▒▒▒▒█░░░░░░░███▒▒▒▒▒▒▒▒▒▒▒▒▒███                \n");
        printf("      ░░░█▒▒▒▒▒▒█░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██              \n");
        printf("      ░░░░█▒▒▒▒▒█░░░██▒▒▒▒▒██▒▒▒▒▒▒██▒▒▒▒▒███             \n");
        printf("      ░░░░░█▒▒▒█░░░█▒▒▒▒▒▒████▒▒▒▒████▒▒▒▒▒▒██            \n");
        printf("      ░░░█████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██            \n");
        printf("      ░░░█▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒██            \n");
        printf("      ░██▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒██▒▒▒▒▒▒▒▒▒▒██▒▒▒▒██            \n");
        printf("      ██▒▒▒███████████▒▒▒▒▒██▒▒▒▒▒▒▒▒██▒▒▒▒▒██            \n");
        printf("      █▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒████████▒▒▒▒▒▒▒██            \n");
        printf("      ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██             \n");
        printf("      ░█▒▒▒███████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██               \n");
        printf("      ░██▒▒▒▒▒▒▒▒▒▒████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█                 \n");
        printf("      ░░████████████░░░█████████████████                  \n");
        printf("\n\n                                                      \n");

        printf("\nParabéns! Você ganhou!\n");
        printf("Você acertou com %d tentativas!\n", tentativa-1);
        printf("Total de pontos: %.2f\n", score);
    }else{

        printf("\n\n                                                      \n");
        printf(" ───────▄▀▀▀▀▀▀▀▀▀▀▄▄                                     \n");
        printf(" ────▄▀▀░░░░░░░░░░░░░▀▄                                   \n");
        printf(" ──▄▀░░░░░░░░░░░░░░░░░░▀▄                                 \n");
        printf(" ──█░░░░░░░░░░░░░░░░░░░░░▀▄                               \n");             
        printf(" ─▐▌░░░░░░░░▄▄▄▄▄▄▄░░░░░░░▐▌                              \n");
        printf(" ─█░░░░░░░░░░░▄▄▄▄░░▀▀▀▀▀░░█                              \n");
        printf(" ▐▌░░░░░░░▀▀▀▀░░░░░▀▀▀▀▀░░░▐▌                             \n");
        printf(" █░░░░░░░░░▄▄▀▀▀▀▀░░░░▀▀▀▀▄░█                             \n");
        printf(" █░░░░░░░░░░░░░░░░▀░░░▐░░░░░▐▌                            \n"); 
        printf(" ▐▌░░░░░░░░░▐▀▀██▄░░░░░░▄▄▄░▐▌                            \n");
        printf(" ─█░░░░░░░░░░░▀▀▀░░░░░░▀▀██░░█                            \n");
        printf(" ─▐▌░░░░▄░░░░░░░░░░░░░▌░░░░░░█                            \n");
        printf(" ──▐▌░░▐░░░░░░░░░░░░░░▀▄░░░░░█                            \n");
        printf(" ───█░░░▌░░░░░░░░▐▀░░░░▄▀░░░▐▌                            \n");
        printf(" ───▐▌░░▀▄░░░░░░░░▀░▀░▀▀░░░▄▀                             \n");
        printf(" ───▐▌░░▐▀▄░░░░░░░░░░░░░░░░█                              \n");
        printf(" ───▐▌░░░▌░▀▄░░░░▀▀▀▀▀▀░░░█                               \n");
        printf(" ───█░░░▀░░░░▀▄░░░░░░░░░░▄▀                               \n");
        printf(" ──▐▌░░░░░░░░░░▀▄░░░░░░▄▀                                 \n");
        printf(" ─▄▀░░░▄▀░░░░░░░░▀▀▀▀█▀                                   \n");
        printf(" ▀░░░▄▀░░░░░░░░░░▀░░░▀▀▀▀▄▄▄▄▄                            \n");
        printf("\n\n                                                      \n");

        printf("Poxa! Você perdeu! Tente novamente!!\n");
    }    
}
