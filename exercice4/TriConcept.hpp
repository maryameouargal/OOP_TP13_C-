#ifndef TRICONCEPT_HPP
#define TRICONCEPT_HPP

#include <iostream>
#include <vector>
#include <functional> // Pour std::less


template <typename T>
void verifierSortable() {
    static_assert(std::is_same<decltype(std::declval<T>() < std::declval<T>()), bool>::value,
                  "Erreur : Le type T doit avoir un operateur < qui renvoie un bool.");
}

// 2. Les foncteurs (functors) pour comparer
struct Asc {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

struct Desc {
    template <typename T>
    bool operator()(const T& a, const T& b) const {
        return a > b; 
    }
};

// 3. Fonction de tri 
template <typename T, typename Comp = std::less<T>>
void quickSort(std::vector<T>& vec, Comp comp = Comp{}) {
    // On verifie que le type est triable avant de faire quoi que ce soit
    verifierSortable<T>();

    if (vec.size() <= 1) return; 

    // Choix du pivot : le dernier element
    T pivot = vec.back();
    
    std::vector<T> gauche, droite;
    
    // Partition (on exclut le pivot en s'arretant a size()-1)
    for (std::size_t i = 0; i < vec.size() - 1; i++) {
        // Si comp(element, pivot) est vrai, il va a gauche
        if (comp(vec[i], pivot)) {
            gauche.push_back(vec[i]);
        } else {
            droite.push_back(vec[i]);
        }
    }
    
    // Appels recursifs
    quickSort(gauche, comp);
    quickSort(droite, comp);
    
    // Reconstruction
    vec.clear();
    for (const T& e : gauche) vec.push_back(e);
    vec.push_back(pivot);
    for (const T& e : droite) vec.push_back(e);
}

#endif