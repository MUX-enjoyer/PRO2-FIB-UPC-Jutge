// Fa servir la classe BinTree antiga (BinTree.hh dels fitxers públics del problema)
#include "BinTree.hh"

// Funció d'immersió: n és el nombre de nodes ja numerats en postordre.
// Retorna l'arbre numerat i deixa n actualitzat amb els nodes de t.
// Cada node es visita un sol cop, per tant el cost és lineal.
BinTree<int> postorderTreeRec(BinTree<int> t, int& n) {
    if (t.empty()) return BinTree<int>();
    // Postordre: primer el fill esquerre, després el dret i finalment l'arrel
    BinTree<int> esq = postorderTreeRec(t.left(), n);
    BinTree<int> dre = postorderTreeRec(t.right(), n);
    ++n;
    return BinTree<int>(n, esq, dre);
}

// Pre:  Sigui T el valor inicial de l'arbre t que es rep com a paràmetre.
// Post: T i l'arbre retornat tenen la mateixa estructura, i cada node de
//       l'arbre retornat guarda la seva posició (des d'1) en el postordre.
BinTree<int> postorderTree(BinTree<int> t) {
    int n = 0;
    return postorderTreeRec(t, n);
}
