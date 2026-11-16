#ifndef ARRAYDYN_HPP
#define ARRAYDYN_HPP

#include <iostream>
#include <stdexcept> 
#include <cstddef>   

template <typename T>
class ArrayDyn {
private:
    T* data;             // Pointeur vers le tableau dynamique
    std::size_t capacite; // Nombre max d'elements
    std::size_t taille;   // Nombre actuel d'elements

    // Petite methode privee pour agrandir le tableau si besoin
    void agrandir() {
        capacite = (capacite == 0) ? 1 : capacite * 2; // On double
        T* nouveauData = new T[capacite];
        for (std::size_t i = 0; i < taille; i++) {
            nouveauData[i] = data[i];
        }
        delete[] data;
        data = nouveauData;
    }

public:
    // 1. Constructeurs et Destructeur (Rule of Three)
    ArrayDyn() : data(nullptr), capacite(0), taille(0) {}

    ArrayDyn(std::size_t cap) : data(nullptr), capacite(cap), taille(0) {
        if (capacite > 0) data = new T[capacite];
    }

    // Constructeur de copie
    ArrayDyn(const ArrayDyn& autre) : data(nullptr), capacite(autre.capacite), taille(autre.taille) {
        if (capacite > 0) {
            data = new T[capacite];
            for (std::size_t i = 0; i < taille; i++) {
                data[i] = autre.data[i];
            }
        }
    }

    // Operateur d'affectation
    ArrayDyn& operator=(const ArrayDyn& autre) {
        if (this != &autre) { 
            // Eviter l'auto-affectation (a = a)
            delete[] data;    // Liberer l'ancienne memoire
            
            capacite = autre.capacite;
            taille = autre.taille;
            data = nullptr;
            
            if (capacite > 0) {
                data = new T[capacite];
                for (std::size_t i = 0; i < taille; i++) {
                    data[i] = autre.data[i];
                }
            }
        }
        return *this;
    }

    // Destructeur
    ~ArrayDyn() {
        delete[] data;
    }

    // 2. Methodes de base
    void push_back(const T& element) {
        if (taille >= capacite) {
            agrandir();
        }
        data[taille] = element;
        taille++;
    }

    void pop_back() {
        if (taille > 0) {
            taille--;
        }
    }

    T& operator[](std::size_t index) {
        if (index >= taille) {
            throw std::out_of_range("Index hors limites !");
        }
        return data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= taille) {
            throw std::out_of_range("Index hors limites !");
        }
        return data[index];
    }

    std::size_t size() const { return taille; }

    // 3. La classe Iterateur personnalise
    class Iterator {
    private:
        T* ptr;
    public:
        Iterator(T* p) : ptr(p) {}

        T& operator*() { return *ptr; }             // Pour lire/ecrire : *it
        Iterator& operator++() { ptr++; return *this; } // Pour avancer : ++it
        Iterator& operator--() { ptr--; return *this; } // Pour reculer : --it
        
        bool operator!=(const Iterator& autre) const {  
            // Pour comparer : it != end
            return ptr != autre.ptr;
        }
    };

    // 4. Methodes begin() et end()
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + taille); }
};

#endif