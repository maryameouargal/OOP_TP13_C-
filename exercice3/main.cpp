#include <iostream>
#include <vector>
#include <string>
#include "Stack.hpp"

using namespace std;

// Fonction utilitaire pour vider une pile (test du pop)
template <typename T>
void viderPile(Stack<T>& s) {
    while (!s.empty()) {
        cout << s.peek() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    cout << " Test de la Stack generique" << endl;

    //Test 1 : Push et peek
    cout << "\nTest 1 : Operations de base" << endl;
    Stack<int> s(5); // capacite de 5
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Sommet (peek) : " << s.peek() << endl; // Doit afficher 30
    cout << "Taille : " << s.size() << endl;       // Doit afficher 3

    // Test 2 : Pop et vidage
    cout << "\n Test 2 : Depilage " << endl;
    cout << "Contenu depile : ";
    viderPile(s);
    cout << "Pile vide ? " << (s.empty() ? "Oui" : "Non") << endl;

    //Test 3 : Gestion des exceptions 
    cout << "\nTest 3 : Exceptions " << endl;
    
    // Test StackUnderflow
    try {
        s.pop(); 
    } catch (const StackUnderflow& e) {
        cout << "Attrape : " << e.what() << endl;
    }

    // Test StackOverflow
    Stack<int> petite(2);
    try {
        petite.push(1);
        petite.push(2);
        petite.push(3); 
    } catch (const StackOverflow& e) {
        cout << "Attrape : " << e.what() << endl;
    }

    // Test 4 : Constructeur avec iterateurs 
    cout << "\nTest 4 : Constructeur par iterateurs " << endl;
    vector<string> mots = {"Bonjour", "le", "monde", "C++"};
    Stack<string> pileMots(mots.begin(), mots.end());
    
    cout << "Contenu de la pile : ";
    viderPile(pileMots);

    //  Test 5 : Gros volume (pas de fuite memoire) 
    cout << "\n Test 5 : Gros volume " << endl;
    {
        Stack<int> grossePile(10000);
        for (int i = 0; i < 10000; i++) {
            grossePile.push(i);
        }
        cout << "10000 elements ajoutes. Sommet : " << grossePile.peek() << endl;
    } 
    cout << "Memoire liberee automatiquement par unique_ptr." << endl;

    return 0;
}