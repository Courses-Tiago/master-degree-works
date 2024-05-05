/*+---------------------------------+
  | Arvore Binaria de Busca - 2024  |
  | By Sandro Izidoro               |
  +---------------------------------+*/

#include <iostream>

using namespace std;

struct No { // DEFINICAO DO NO
  int Info; // INFORMACAO DO NO
  No* Esq; // PONTEIRO PARA SUBARVORE ESQ
  No* Dir; // PONTEIRO PARA SUBARVORE DIR
};

typedef No* Arvore; // DEFINE TIPO ARVORE

void IniciaArvore (Arvore &); // INICIA A ARVORE
void InsereAbbRec (Arvore &, int); // INSERE NO - RECURSIVO
void Preordem (Arvore); // PERCURSO PRE-ORDEM
void Ordem (Arvore); // PERCURSO EM ORDEM
void Posordem (Arvore); // PERCURSO POS-ORDEM
bool ArvoreVazia (Arvore); // VERIFICA ARVORE VAZIA
void ApagaNo (Arvore &); // APAGA NO
void ApagaArvore (Arvore &); // APAGA ARVORE
int  ContaNos (Arvore); // CONTA NOS
void RemoveAbbRec(Arvore& A, int Info); // REMOVE NO


int main () {

  Arvore A;
  IniciaArvore(A);

  InsereAbbRec(A, 10);
  InsereAbbRec(A, 5);
  InsereAbbRec(A, 15);
  InsereAbbRec(A, 8);
  InsereAbbRec(A, 12);
  InsereAbbRec(A, 18);
  InsereAbbRec(A, 2);

  cout << "Arvore em Ordem antes de remover: ";
  Ordem(A);
  cout << endl;

  RemoveAbbRec(A, 10);
  // RemoveAbbRec(A, 5);
  RemoveAbbRec(A, 15);
  // RemoveAbbRec(A, 8);
  // RemoveAbbRec(A, 12);
  // RemoveAbbRec(A, 18);
  RemoveAbbRec(A, 2);

  cout << "Arvore em Ordem depois de remover: ";
  Ordem(A);
  cout << endl;

  cout << "A arvore tem " << ContaNos(A) << " nos." << endl;

  ApagaArvore(A);

   return 0;
}

// IMPLEMENTACAO DAS FUNCOES

// INICIA A ARVORE
void IniciaArvore(Arvore &Raiz){
    Raiz = nullptr;
}

// ARVORE VAZIA
bool ArvoreVazia (Arvore A){
   if(A!=nullptr)
    return false;
   return true;
}

// APAGA NO
void ApagaNo (Arvore &A){
  if(A == nullptr)
     return;
  ApagaNo(A->Esq);
  ApagaNo(A->Dir);
  delete A;
}

// APAGA ARVORE
void ApagaArvore (Arvore &A){
  if(A==nullptr)
     return;
  ApagaNo(A);
  IniciaArvore(A);
}

// INSERCAO DE UM NO NA ARVORE - RECURSIVA
void InsereAbbRec (Arvore &A, int Info){
  if(A == nullptr){ // SE PONTEIRO NULO, INSERIR UM NOVO NO
    A = new No;
    A->Info = Info;
    A->Esq = A->Dir = nullptr;
  }
  else if(Info > A->Info)
         InsereAbbRec(A->Dir, Info); //INSERINDO NO RAMO DIREITO
       else
         InsereAbbRec(A->Esq, Info); //INSERINDO NO RAMO ESQUERDO
}

// CAMINHAMENTO EM PRE-ORDEM
void Preordem (Arvore A) {
  if(A!=nullptr) {
    cout << A->Info << "  ";
    Preordem (A->Esq);
    Preordem (A->Dir);
  }
}

// CAMINHAMENTO EM ORDEM
void Ordem (Arvore A) {
  if(A!=nullptr) {
    Ordem (A->Esq);
    cout << A->Info << "  " ;
    Ordem (A->Dir);
  }
}

// CAMINHAMENTO EM POS-ORDEM
void Posordem (Arvore A) {
  if(A!=nullptr) {
    Posordem (A->Esq);
    Posordem (A->Dir);
    cout << A->Info << "  ";
  }
}

// CONTA NOS
int ContaNos (Arvore A) {
  if(A!=NULL)
	return 1 + ContaNos(A->Esq) + ContaNos(A->Dir);
  return 0;
}

void RemoveAbbRec(Arvore& A, int Info) {

  if(A == nullptr) {
  // Árvore está vazia ou o dado não foi encontrado 
    cout << "Dado não encontrado na árvore" << endl;
    return;
  }

  if(Info > A->Info) {
  // O dado a ser removido é maior do que o nó atual, então procura na subarvore a direita
    RemoveAbbRec(A->Dir, Info);
    return;
  }

  // O dado a ser removido é menor do que o nó atual, então procura na subarvore a esquerda
  if(Info < A->Info) {
    RemoveAbbRec(A->Esq, Info);
    return;
  }

  // Se chegou aqui é porque o dado foi encontrado

  Arvore remover;

  // Caso 1: O nó a ser removido possui um um ramo a direita e a esquerda

  if(A->Esq != nullptr && A->Dir != nullptr) {

    // O primeiro nó a direita do dado a ser removido é também o menor nó do ramo a direita
    if(A->Dir->Esq == nullptr) {
      remover = A->Dir;
      A->Info = A->Dir->Info;
      A->Dir = A->Dir->Dir;
      delete remover;
      return;
    }

    // Encontra o menor nó do ramo a direita do dado a ser removido
    Arvore aux = A->Dir;
    while(aux->Esq->Esq != nullptr) {
      aux = aux->Esq;
    }

    // O nó com o dado a ser removido é atualizado com o dado do menor nó do ramo a direita
    remover = aux->Esq;
    A->Info = aux->Esq->Info;
    aux->Esq = aux->Esq->Dir;
    delete remover;
    return;
  }


  // Caso 2: O nó a ser removido não possui ramo a esquerda ou a direita

  if(A->Dir == nullptr) {
    //Não possui ramo a direita, então subistitui o nó com o dado a ser removido pelo primeiro nó do ramo a esquerda
    remover = A;
    A = A->Esq;
    delete remover;
    return;
  }

  if(A->Esq == nullptr) {
    remover = A;
    A = A->Dir;
    delete remover;
    return;
  }
}
