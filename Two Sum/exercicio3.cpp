#include <string>
#include <vector> 
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> indices;
        int j, k;

        for (j = 0; j < nums.size (); j++) {
            for (k = j + 1; k < nums.size (); k++) {
                if (nums [j] + nums [k] == target) {
                    indices.push_back (j);
                    indices.push_back (k);

                    break;
                }
            }
        }

        return indices;
    }
};

int main() {
    Solution solucao;
    int i, target = 3;

    std::vector<int> entrada, saida;

    entrada.push_back (1);
    entrada.push_back (2);

    printf ("Vetor de entrada: ");
    
    for (i = 0; i < (int) entrada.size (); i++) {
        printf ("%d, ", entrada [i]);
    }

    printf ("\n\r\n\rTarget de entrada: %d\n\r\n\r", target);
    
    saida = solucao.twoSum (entrada, target);

    printf ("Vetor de saida: ");
    
    for (i = 0; i < (int) saida.size (); i++) {
        printf ("%d, ", saida [i]);
    }


}