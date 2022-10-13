#include <string>
#include <vector> 
#include <iostream>
#include <math.h>

class Solution {
public:
    bool isValid(std::string s) {
        int i;
        std::string pilha = "";
 
        // check for constraint #1
        if ((s.length () < 1) || (s.length() > pow (10.0, 4.0))) {
            return false;
        }

        // logical constraint
        if ((s.length () % 2) != 0) {
            return false;
        }

        // fetches every character in the string
        for (i = 0; i < s.length (); i++) {
            // check for constraint #2
            if ((s [i] != '(') && (s [i] != ')') && (s [i] != '[') && (s [i] != ']') && (s [i] != '{') && (s [i] != '}')) {
                return false;
            }

            // test if it's an opening symbol
            if ((s [i] == '(') || (s [i] == '[') || (s [i] == '{')) {
                // push into the stack
                pilha = pilha + s [i];
            } else {
                if (pilha.length () < 1)
                {
                    return false;
                }
                
                if ((s [i] == ')') && (pilha [pilha.length () - 1] != '(')) {
                    return false;
                } else if ((s [i] == ']') && (pilha [pilha.length () - 1] != '[')) {
                    return false;
                } else if ((s [i] == '}') && (pilha [pilha.length () - 1] != '{')) {
                    return false;
                } else {
                    pilha = pilha.substr (0, pilha.length () - 1);
                }
                
            }
            
        }

        return (pilha.length () == 0);
    }
};

int main() {
    Solution solucao;
    int i;

    std::string entrada = "){";

    printf ("String de entrada: ");

    std::cout << entrada + "\n\r";

    printf ("Tamanho do string de entrada: %d\n\r\n\r", entrada.length());
    
    if (solucao.isValid (entrada)) {
        printf ("Valido\n\r");
    } else {
        printf ("Invalido\n\r");
    }
    
    return 0;
}