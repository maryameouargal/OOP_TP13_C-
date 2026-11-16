#include <iostream>
#include <vector>
#include <string>
#include "TriConcept.hpp"

using namespace std;

// Une structure utilisateur pour tester le concept
class Personne {
public:
    string nom;
    int age;

    Personne(string n, int a) : nom(n), age(a) {}

    // On doit definir operator< pour satisfaire le concept Sortable
    bool operator<(const Personne& autre) const {
        return this->age < autre.age; // Tri par age
    }

    // Ami pour l'affichage
    friend ostream& operator<<(ostream& os, const Personne& p) {
        os << p.nom << " (" << p.age << " ans)";
        return os;
    }
};

// Fonction de test unitaire simple
template <typename T>
bool estTrie(const vector<T>& v) {
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < v[i-1]) return false; // Le suivant est plus petit : pas trie
    }
    return true;
}

int main() {
    cout << " Test du tri avec concepts C++20 " << endl;

    // Test 1 : int croissant 
    cout << "\nTest 1 : int croissant" << endl;
    vector<int> v1 = {5, 2, 8, 1, 9, 3};
    quickSort(v1); 
    for (int n : v1) cout << n << " ";
    cout << "\nTest unitaire : " << (estTrie(v1) ? "OK" : "ECHEC") << endl;

    // Test 2 : int decroissant 
    cout << "\n Test 2 : int decroissant" << endl;
    vector<int> v2 = {5, 2, 8, 1, 9, 3};
    // Utilise notre foncteur Desc
    quickSort(v2, Desc{}); 
    for (int n : v2) cout << n << " ";
    cout << endl;

    // Test 3 : string 
    cout << "\n Test 3 : string " << endl;
    vector<string> v3 = {"Zebre", "Chat", "Ane", "Banane"};
    quickSort(v3);
    for (const string& s : v3) cout << s << " ";
    cout << "\nTest unitaire : " << (estTrie(v3) ? "OK" : "ECHEC") << endl;

    // Test 4 : Objet utilisateur 
    cout << "\n Test 4 : Objet Personne (tri par age)" << endl;
    vector<Personne> v4 = {
        Personne("Preston", 30),
        Personne("Rina", 22),
        Personne("Marcus", 25)
    };
    quickSort(v4);
    for (const Personne& p : v4) cout << p << " | ";
    cout << "\nTest unitaire : " << (estTrie(v4) ? "OK" : "ECHEC") << endl;

    return 0;
}