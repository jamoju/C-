#include <string>
#include <vector> 
#include <iostream>
#include <math.h>

class Solution {
public:
    void imprimeVetor (std::vector<int>& nums, int tam, int val) {
        int i;

        printf ("val: %d\n\r", val);
        printf ("nums.size (): %d\n\r", tam);
        printf ("nums: [");

        for (i = 0; i < tam; i++) {
            printf ("%d", nums [i]);

            if (i < tam - 1) {
                printf (", ");
            }
        }

        printf ("]\n\r\n\r");
    }

    int removeElement(std::vector<int>& nums, int val) {
        int i,
            j,
            hits = 0,
            temp;

char c;

        for (i = 0; i < (nums.size () - hits); ) {

//imprimeVetor (nums, nums.size(), val);
//printf ("nums [i] (%d) == val (%d) / i: %d\r\n", nums [i], val, i);
//std::cin >> c;
            if (nums [i] == val) {
                for (j = i; j < (nums.size () - 1); j++) {
                    temp = nums [j];
                    nums [j] = nums [j + 1];
                    nums [j + 1] = temp;
                }

                hits++;
            } else {
                i++;
            }
        }          

        return nums.size () - hits;
    }
};

int main() {

    Solution solucao;
//    std::vector<int> vetorEntrada = {1};
//    std::vector<int> vetorEntrada = {1, 1, 2};
//    std::vector<int> vetorEntrada = {0,0,0,0,1,1,1,2,2,3,3,4};
//    std::vector<int> vetorEntrada  = {-3,-1,-1,0,0,0,0,0,2};
//    std::vector<int> vetorEntrada  = {1,1};
//    std::vector<int> vetorEntrada  = {1,2,2};
//    std::vector<int> vetorEntrada = {0,0,0,0,1,1,1,2,2,3,3,4,4,4,4,4,4,4};
//    std::vector<int> vetorEntrada = {3,2,2,3};
//    std::vector<int> vetorEntrada = {0,1,2,2,3,0,4,2};
    std::vector<int> vetorEntrada = {2,2};

    int i,
        tamanhoFinal,
        valorEntrada = 2;

    printf ("Inicio\n\r");

    solucao.imprimeVetor (vetorEntrada, vetorEntrada.size(), valorEntrada);

    tamanhoFinal = solucao.removeElement (vetorEntrada, valorEntrada);

    printf ("Fim\n\r");

    solucao.imprimeVetor (vetorEntrada, tamanhoFinal, valorEntrada);

    return 0;
}