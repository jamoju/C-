#include <string>
#include <vector> 
#include <iostream>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int j, k;
        std::string resultado = "";
        bool commonprefixfound = false;

        if (strs.size () < 1 || strs.size () > 200) {
            return "INVALID VECTOR";
        }

        for (j = 0; j < strs.size(); j++) {
            if (strs [j].length () > 200) {
                return "INVALID ELEMENT IN VECTOR";
            } else {
                for (k = 0; k < strs [j].length (); k++) {
                    if ((strs [j] [k] < 'a') || (strs [j] [k] > 'z')) {
                        return "INVALID CHARACTER IN ELEMENT IN VECTOR";
                    }
                }
           }
        }

        for (j = 0; ((j <= strs [0].length ()) && (!(commonprefixfound))); j++) {
            resultado = strs [0].substr (0, strs [0].length () - j);
            
            if (resultado.length () == 0) {
                break;
            }

            commonprefixfound = true;

            for (k = 1; (k < strs.size() && commonprefixfound); k++) {
                commonprefixfound = (strs [k].substr (0, resultado.length ()) == resultado);
            }
        }

        return resultado;
    }
};

int main() {
    Solution solucao;
    int i;

    std::vector<std::string> entrada {};
    std::string saida;

    entrada.push_back ("flower");
    entrada.push_back ("flow");
    entrada.push_back ("flight");
//    entrada.push_back ("dog");
//    entrada.push_back ("racecar");
//    entrada.push_back ("car");

    printf ("Vetor de entrada: ");
    
    for (i = 0; i < (int) entrada.size (); i++) {
        std::cout << entrada [i] + ", ";
    }

    saida = solucao.longestCommonPrefix (entrada);

    printf ("\n\r\n\rSaida: ");
    
    std::cout << saida;
    
    return 0;
}