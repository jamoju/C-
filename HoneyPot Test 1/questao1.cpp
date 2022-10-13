#include <string>
#include <vector> 
#include <iostream>
#include <math.h>

class Solution {
private:
    bool fechIndex (int index, int indexes_count, int *indexes_paired) {
        int i;
        bool indexFound = false;

        // busca o elemento no vetor
        for (i = 0; ((i < indexes_count) && (!(indexFound))); i++) {
            indexFound = (indexes_paired [i] == index);
        }

        return indexFound;
    }

public:
    int minimizeBias(int ratings_count, int* ratings) {
    
        int bias,
            i,
            j,
            k = 0,
            l,
            ratings_paired [ratings_count * 2],
            totalPairsFound = 0,
            totalBiasAmount = 0;
        bool foundAPair,
             foundNextI;
        
        // first constraint
        if (ratings_count < 1 || ratings_count > pow (10.0, 5.0)) {
            return -1; // return error code for broken first constraint
        }
        
        // fetch the input array testing each element according to the second constraint
        for (i = 0; i < ratings_count; i++) {
            if (ratings [i] < 1 || ratings [i] > pow (10.0, 5.0)) {
                return -2; // return error code for broken second constraint
            }
        }
        
        // third constraint
        if (ratings_count % 2 != 0) {
            return -3; // return error code for broken third constraint
        }
        
//        for (bias = 0; k < ratings_count; bias++)
        for (bias = 0; bias < 4; bias++)
        {
            printf ("\n\rbias: %d ", bias);


            foundAPair = false;

            i = 0;

            do
            {
                if (!(fechIndex (i, k, ratings_paired))) {
                    break;
                }

                i++;
            } while (i < ratings_count);
                
            for (; i < (ratings_count - 1); i++) {
                printf ("i: %d ", i);

                j = i + 1;

                do
                {
                    if (!(fechIndex (j, k, ratings_paired))) {
                        break;
                    }

                    j++;
                } while (j < ratings_count);

                for (; j < ratings_count; j++) {
                    printf ("j: %d ", j);

                    if (abs (ratings [i] - ratings [j]) == bias) {
                        printf (" encontrei um par! ");
                        // increase the total of pairs found
                        totalPairsFound++;
                        //printf (" totalPairsFound: %d", totalPairsFound);

                        // sum up the total bias calculated
                        totalBiasAmount = totalBiasAmount + abs (ratings [i] - ratings [j]);
                        //printf (" totalBiasAmount: %d", totalBiasAmount);

                        // sinaliza que achou um par
                        foundAPair = true;
                        //if (foundAPair) {
                        //    printf (" foundAPair: true");
                        //}
                        //else {
                        //    printf (" foundAPair: false");
                        //}

                        // armazena os índices dos pares encontrados
                        ratings_paired [k] = i;
                        ratings_paired [k + 1] = j;
                        //printf (" ratings_paired [k]: %d, ratings_paired [k + 1]: %d", ratings_paired [k], ratings_paired [k + 1]);

                        // incrementa o índice
                        k = k + 2;
                        //printf (" k: %d", k);
                    }

                    if (foundAPair) {
                        // sai do loop do j
                        break;
                    }
                }

                if (foundAPair) {
                    // sai do loop do i
                    break;
                }
            }

            printf ("ratings_paired: [");
            
            for (l = 0; l < k; l++) {
                printf ("%d", ratings_paired [l]);

                if ((l + 1) == k) {
                    printf ("]\n\r\n\r");
                }
                else {
                    printf (", ");
                }
            }
        }

        return totalBiasAmount;
    }
};

int main() {
    Solution solucao;
    
    int i,
        tamanho_vetor_entrada = 6,
        vetor_entrada [tamanho_vetor_entrada],
        saida;

    vetor_entrada [0] = 1;
    vetor_entrada [1] = 2;
    vetor_entrada [2] = 2;
    vetor_entrada [3] = 4;
    vetor_entrada [4] = 3;
    vetor_entrada [5] = 4;



    printf ("Tamanho vetor de entrada: %d\n\r");
    printf ("Vetor de entrada: [");
    
    for (i = 0; i < tamanho_vetor_entrada; i++) {
        printf ("%d", vetor_entrada [i]);

        if ((i + 1) == tamanho_vetor_entrada) {
            printf ("]\n\r\n\r");
        }
        else {
            printf (", ");
        }
    }

    saida = solucao.minimizeBias (tamanho_vetor_entrada, vetor_entrada);

    //printf ("\n\r\n\rSaida: ");
    
    //std::cout << saida;
    
    return 0;
}