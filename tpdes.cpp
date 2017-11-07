#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <bitset>

//Fonctions à implémenter:

// Fonction de permutation (IP)
std::bitset<8> permutation_ip(std::bitset<8> octet)
{
  std::bitset<8>  octetTempo;
  std::cout << "octet à tester:" << octet << std::endl;
  // std::cout << ":" << octet[0] << std::endl;
  // std::cout << ":" << octet[1] << std::endl;
  for(int i = 0; i < octet.size(); i++)
    std::cout << octet[i] << std::endl;
  octetTempo[0] =  octet[1];
  octetTempo[1] =  octet[5];
  octetTempo[2] =  octet[2];
  octetTempo[3] =  octet[0];
  octetTempo[4] =  octet[3];
  octetTempo[5] =  octet[7];
  octetTempo[6] =  octet[4];
  octetTempo[7] =  octet[6];
  return  octetTempo;
}

// Fonction de permutation (IP-1)
std::bitset<8> permutation_ip_moinsun(std::bitset<8> octet)
{
  std::bitset<8> octetTempo;
  octetTempo[0] =  octet[3];
  octetTempo[1] =  octet[0];
  octetTempo[2] =  octet[2];
  octetTempo[3] =  octet[4];
  octetTempo[4] =  octet[6];
  octetTempo[5] =  octet[1];
  octetTempo[6] =  octet[7];
  octetTempo[7] =  octet[5];
  return  octetTempo;
}
// Fonction de génération des deux sous-clés

// Fonction de permutation des 4 bits (SW)

// La fonction fk

int main(int argc, char ** argv)
{
  // ici, ouverture et parcours de fichier.
  // Envoi vers les autres fonctions caractère par caractère
  std::bitset<8> octet;
  std::bitset<8> octet2 { 'A' }; 

  std::cout << octet2 << std::endl;

  octet = permutation_ip(octet2);
    
  std::cout << octet << std::endl;


  return 0;
  
}
