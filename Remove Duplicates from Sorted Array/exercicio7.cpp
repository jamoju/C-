#include <string>
#include <vector> 
#include <iostream>
#include <math.h>

class Solution {
public:
    int removeDuplicatesV1(std::vector<int>& nums) {
        int i,
            j,
            temp;

        for (i = 0; i < (nums.size () - 1); ) {
            for (j = i + 1; j < nums.size (); j++) {
                if (nums [i] == nums [j]) {
                    nums [j] = 1000 + abs(nums [j]);
                } else {
                    i = j;

                    break;
                }
            }
        }

        for (i = 0; i < (nums.size () - 1); i++) {
            for (j = i + 1; j < nums.size (); j++) {
                if (nums [j] < nums [i]) {
                    temp = nums [i];
                    nums [i] = nums [j];
                    nums [j] = temp;
                }
            }
        }

        for (i = 0; i < nums.size () && nums [i] < 1000; i++);

        return i;
    }

    int removeDuplicates(std::vector<int>& nums) {
        int i,
            j,
            k,
            reps = 0,
            tamanhoFinal = nums.size ();

        if (nums.size () == 1) {
            return nums.size ();
        }

        for (i = 0; i < (tamanhoFinal - 1); i++) {
            for (j = i + 1; j < tamanhoFinal; j++) {
                if (nums [i] == nums [j]) {
                    reps++;
                } else {
                    tamanhoFinal = tamanhoFinal - reps;

                    for (k = i + 1; k < tamanhoFinal; k++) {
                        nums [k] = nums [k + reps];
                    }

                    break;
                }
            }

            if (j == tamanhoFinal && reps > 0 && nums [i] == nums [j - 1]) {
                tamanhoFinal = tamanhoFinal - reps;                
            }

            reps = 0;
        }

        return tamanhoFinal;
    }
};

int main() {

    Solution solucao;
//    std::vector<int> entrada = {1};
//    std::vector<int> entrada = {1, 1, 2};
//    std::vector<int> entrada = {0,0,0,0,1,1,1,2,2,3,3,4};
//    std::vector<int> entrada  = {-3,-1,-1,0,0,0,0,0,2};
//    std::vector<int> entrada  = {1,1};
//    std::vector<int> entrada  = {1,2,2};
    std::vector<int> entrada = {0,0,0,0,1,1,1,2,2,3,3,4,4,4,4,4,4,4};
    int i,
        tamanhoFinal;

    printf ("Entrada: [");

    for (i = 0; i < entrada.size (); i++) {
        printf ("%d", entrada [i]);

        if (i < entrada.size () - 1) {
            printf (", ");
        }
    }

    printf ("]\n\r\n\r");

    tamanhoFinal = solucao.removeDuplicatesV1 (entrada);

    printf ("Tamanho final: %d\n\r", tamanhoFinal);

    printf ("Saida: [");

    for (i = 0; i < tamanhoFinal; i++) {
        printf ("%d", entrada [i]);

        if (i < tamanhoFinal - 1) {
            printf (", ");
        }
    }

    printf ("]\n\r\n\r");

    return 0;
}