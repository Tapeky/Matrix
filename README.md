# Matrix - Projet d'Algèbre Linéaire

## Structure du projet

```
Matrix/
├── include/          # Headers (.hpp)
│   ├── Vector.hpp
│   ├── Matrix.hpp
│   └── Utils.hpp
├── src/             # Implémentations (.tpp) et exercices
│   ├── Matrix.tpp
│   ├── Utils.tpp
│   └── ex00/        # Exercices créés au fur et à mesure
├── tests/           # Fichiers de test
│   └── test_main.cpp
├── docs/            # Documentation
│   ├── Matrix.pdf
│   └── Matrix_condensed.txt
├── build/           # Exécutables compilés
├── .gitignore
└── README.md
```

## Compilation

```bash
# Depuis le dossier Matrix/
g++ -I include -o build/test tests/test_main.cpp

# Ou pour un exercice spécifique
g++ -I include -o build/ex00 src/ex00/main.cpp
```

## Classes implémentées

- **Vector<T>** : Vecteur dynamique avec opérations de base
- **Matrix<T>** : Matrice avec stockage linéaire
- **Utils** : Fonctions de conversion Vector ↔ Matrix

## Fonctionnalités

- [x] Fonction size/shape pour vecteurs et matrices
- [x] Fonction pour vérifier si une matrice est carrée
- [x] Fonction d'affichage pour vecteurs et matrices
- [x] Fonction de reshape Vector ↔ Matrix