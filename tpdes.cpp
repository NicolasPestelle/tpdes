#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <bitset>

// Actuellement, le code me retourne bien 1111 pour la première partie du codage de A
// Cependant la valeur est faussée dans la deuxième partie
// Toutes les fonctions sont cependant implementées 
// On a voulu essayer d'utiliser les bitset, ce qui a par la suite provoqué plus de problemes que de solutions
// ce qui explique notre code inachevé

int S0[4][4] = {{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
int S1[4][4] = {{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
  
std::bitset<4> get_partie_droite(std::bitset<8> octet)
{
  std::bitset<4> demiOctet;
  
  demiOctet[0] = octet[0];
  demiOctet[1] = octet[1];
  demiOctet[2] = octet[2];
  demiOctet[3] = octet[3];
  
  return demiOctet;
}


std::bitset<4> get_partie_gauche(std::bitset<8> octet)
{
  std::bitset<4> demiOctet;
  
  demiOctet[0] = octet[4];
  demiOctet[1] = octet[5];
  demiOctet[2] = octet[6];
  demiOctet[3] = octet[7];
  
  return demiOctet;
}



std::bitset<10> permutation_p10(std::bitset<10> octet)
{
  std::bitset<10>  octetTempo;
  octetTempo[9] =  octet[7];
  octetTempo[8] =  octet[5];
  octetTempo[7] =  octet[8];
  octetTempo[6] =  octet[3];
  octetTempo[5] =  octet[6];
  octetTempo[4] =  octet[0];
  octetTempo[3] =  octet[9];
  octetTempo[2] =  octet[1];
  octetTempo[1] =  octet[2];
  octetTempo[0] =  octet[4];

  return  octetTempo;  
}

std::bitset<5> permutation_a_gauche(std::bitset<5> bits)
{
  std::bitset<1> tmp;
  tmp[0] = bits[bits.size()-1];
  bits <<= 1;
  bits[0] = tmp[0]; 
  return bits;
}

std::bitset<8>permutation_p8(std::bitset<10> octet)
{
  std::bitset<8>  octetTempo;

  octetTempo[7] =  octet[4];
  octetTempo[6] =  octet[7];
  octetTempo[5] =  octet[3];
  octetTempo[4] =  octet[6];
  octetTempo[3] =  octet[2];
  octetTempo[2] =  octet[5];
  octetTempo[1] =  octet[0];
  octetTempo[0] =  octet[1];
  
  return  octetTempo;  
}

std::bitset<4>permutation_p4(std::bitset<4> bits)
{
  std::bitset<4>  bitsTempo;

  bitsTempo[3] =  bits[2];
  bitsTempo[2] =  bits[0];
  bitsTempo[1] =  bits[1];
  bitsTempo[0] =  bits[3];
  
  return  bitsTempo;  
}

std::bitset<8> generation_k1(std::bitset<10> cle)
{
  std::bitset<10> clePermutee = permutation_p10(cle);
  std::bitset<5> clePartieDroite;
  std::bitset<5> clePartieGauche;

  clePartieDroite[0] = clePermutee[0];
  clePartieDroite[1] = clePermutee[1];
  clePartieDroite[2] = clePermutee[2];
  clePartieDroite[3] = clePermutee[3];
  clePartieDroite[4] = clePermutee[4];
  clePartieGauche[0] = clePermutee[5];
  clePartieGauche[1] = clePermutee[6];
  clePartieGauche[2] = clePermutee[7];
  clePartieGauche[3] = clePermutee[8];
  clePartieGauche[4] = clePermutee[9];

  clePartieGauche = permutation_a_gauche(clePartieGauche);
  clePartieDroite = permutation_a_gauche(clePartieDroite);
  
  cle[9] = clePartieGauche[4];
  cle[8] = clePartieGauche[3];
  cle[7] = clePartieGauche[2];
  cle[6] = clePartieGauche[1];
  cle[5] = clePartieGauche[0];
  cle[4] = clePartieDroite[4];
  cle[3] = clePartieDroite[3];
  cle[2] = clePartieDroite[2];
  cle[1] = clePartieDroite[1];
  cle[0] = clePartieDroite[0];

  return permutation_p8(cle);  
}


std::bitset<8> generation_k2(std::bitset<10> cle)
{
  std::bitset<10> clePermutee = permutation_p10(cle);
  std::bitset<5> clePartieDroite;
  std::bitset<5> clePartieGauche;


  clePartieDroite[0] = clePermutee[0];
  clePartieDroite[1] = clePermutee[1];
  clePartieDroite[2] = clePermutee[2];
  clePartieDroite[3] = clePermutee[3];
  clePartieDroite[4] = clePermutee[4];
  clePartieGauche[0] = clePermutee[5];
  clePartieGauche[1] = clePermutee[6];
  clePartieGauche[2] = clePermutee[7];
  clePartieGauche[3] = clePermutee[8];
  clePartieGauche[4] = clePermutee[9];


  clePartieGauche = permutation_a_gauche(clePartieGauche);
  clePartieDroite = permutation_a_gauche(clePartieDroite);

  clePartieGauche = permutation_a_gauche(clePartieGauche);
  clePartieDroite = permutation_a_gauche(clePartieDroite);

  clePartieGauche = permutation_a_gauche(clePartieGauche);
  clePartieDroite = permutation_a_gauche(clePartieDroite);
  

  cle[9] = clePartieGauche[4];
  cle[8] = clePartieGauche[3];
  cle[7] = clePartieGauche[2];
  cle[6] = clePartieGauche[1];
  cle[5] = clePartieGauche[0];
  cle[4] = clePartieDroite[4];
  cle[3] = clePartieDroite[3];
  cle[2] = clePartieDroite[2];
  cle[1] = clePartieDroite[1];
  cle[0] = clePartieDroite[0];

  return permutation_p8(cle);  
}

char conversion_bit_to_char(std::bitset<8> octet)
{
  return  char(octet.to_ulong()); 
}

std::bitset<8> conversion_char_to_bits(unsigned char byte)
{
  return std::bitset<8>(byte);
}

std::bitset<8> permutation_ip(std::bitset<8> octet)
{
  std::bitset<8>  octetTempo;
  octetTempo[7] =  octet[6];
  octetTempo[6] =  octet[2];
  octetTempo[5] =  octet[5];
  octetTempo[4] =  octet[7];
  octetTempo[3] =  octet[4];
  octetTempo[2] =  octet[0];
  octetTempo[1] =  octet[3];
  octetTempo[0] =  octet[1];
  return  octetTempo;
}


std::bitset<8> permutation_ip_moinsun(std::bitset<8> octet)
{
  std::bitset<8> octetTempo;
  octetTempo[7] =  octet[4];
  octetTempo[6] =  octet[7];
  octetTempo[5] =  octet[5];
  octetTempo[4] =  octet[3];
  octetTempo[3] =  octet[1];
  octetTempo[2] =  octet[6];
  octetTempo[1] =  octet[0];
  octetTempo[0] =  octet[2];
  return  octetTempo;
}



std::bitset<8> permutation_sw(std::bitset<8> octet)
{
  std::bitset<8> newOctet;
  std::bitset<4> partieDroite = get_partie_droite(octet);
  std::bitset<4> partieGauche = get_partie_gauche(octet);

  newOctet[0] =  partieGauche[0];
  newOctet[1] =  partieGauche[1];
  newOctet[2] =  partieGauche[2];
  newOctet[3] =  partieGauche[3];
  newOctet[4] =  partieDroite[0];
  newOctet[5] =  partieDroite[1];
  newOctet[6] =  partieDroite[2];
  newOctet[7] =  partieDroite[3];

  return newOctet;    
}


std::bitset<4> fonction_fk(std::bitset<4> demiIP, std::bitset<4> bitsP4)
{
  return demiIP ^= bitsP4;
}

std::bitset<8> calcul_ep(std::bitset<4> demiOctet)
{
  std::bitset<8> ep;
  ep[7] =  demiOctet[0];
  ep[6] =  demiOctet[3];
  ep[5] =  demiOctet[2];
  ep[4] =  demiOctet[1];
  ep[3] =  demiOctet[2];
  ep[2] =  demiOctet[1];
  ep[1] =  demiOctet[0];
  ep[0] =  demiOctet[3];
  return ep;
}

std::bitset<4> traitement_matrices(std::bitset<8> resultatXOR)
{
  std::bitset<4> sortieSbox;

  int ligneS0 = resultatXOR[7]*2 + resultatXOR[4];
  int colonneS0 = resultatXOR[6]*2 + resultatXOR[5];
  int ligneS1 = resultatXOR[3]*2 + resultatXOR[0];
  int colonneS1 = resultatXOR[2]*2 + resultatXOR[1];
  int valeurS0 = S0[colonneS0][ligneS0];
  int valeurS1 = S1[colonneS1][ligneS1];

  if( valeurS0 >= 2)
    sortieSbox[3]=1;
  else  sortieSbox[3]=0;
  if(valeurS0 -2 > 0)
    sortieSbox[2]=1;
  else  sortieSbox[2]=0;
  if( valeurS1 >= 2)
    sortieSbox[1]=1;
  else  sortieSbox[1]=0;
  if(valeurS1 -2 > 0)
    sortieSbox[0]=1;
  else  sortieSbox[0]=0;

  return permutation_p4(sortieSbox);
}

void cryptage_tpdes(char caractere,  std::bitset<10> cle)
{

  // Premiere itération, K1
  std::bitset<8> clek1 = generation_k1(cle);
  std::bitset<8> clek2 = generation_k2(cle);
  std::bitset<8> octet = conversion_char_to_bits(caractere);
  std::bitset<8> octetIP = permutation_ip(octet);
  std::bitset<4> octetPartieDroite  = get_partie_droite(octetIP);
  std::bitset<8> ep = calcul_ep(octetPartieDroite);
  std::bitset<8> resultatXOR = ep^=clek1;
  std::bitset<4> sortieSbox = traitement_matrices(resultatXOR);
  std::bitset<4> octetPartieGauche  = get_partie_gauche(octetIP);
  std::bitset<4> resultatFK1 = fonction_fk(octetPartieGauche, sortieSbox);

  // Deuxieme itération, K2
  octetIP = permutation_sw(octetIP);
  octetPartieDroite  = get_partie_droite(octetIP);
  ep = calcul_ep(octetPartieDroite);
  resultatXOR = ep^=clek2; 
  sortieSbox = traitement_matrices(resultatXOR);
  octetPartieGauche  = get_partie_gauche(octetIP);
  std::bitset<4> resultatFK2 = fonction_fk(octetPartieGauche, sortieSbox);

  std::cout << "Resultat K1 : " << resultatFK1 << std::endl;
  std::cout << "Resultat K2 : " << resultatFK2 << std::endl;
  // Resultat K1 correspond à la partie droite, et K2 à la partie gauche, ainsi:

  std::bitset<8> resultatFinal;
  resultatFinal[7] = resultatFK2[3];
  resultatFinal[6] = resultatFK2[2];
  resultatFinal[5] = resultatFK2[1];
  resultatFinal[4] = resultatFK2[0];
  resultatFinal[3] = resultatFK1[3];
  resultatFinal[2] = resultatFK1[2];
  resultatFinal[1] = resultatFK1[1];
  resultatFinal[0] = resultatFK1[0];

  resultatFinal =  permutation_ip_moinsun(resultatFinal);

  std::cout << "Resultat du cryptage du caractere : " << resultatFinal << std::endl;
  std::cout << "Cela correspond au caractere : " <<  conversion_bit_to_char(resultatFinal) << std::endl;
}

int main(int argc, char ** argv)
{
  std::string maString;
      
  if (argc < 3)
    {
      std::cout << "Pas assez d'arguments, utilisez le format ./a.out <texte> <cle> " << std::endl;
    }
  else
    {
      std::ifstream fichier(argv[1], std::ios::in);
      std::bitset<10> cle (argv[2]);
      
      if(fichier)  
	{       
	  while(getline(fichier, maString))  // Chiffrement du texte ligne par ligne. 
	    {
	      for(int i = 0; i < maString.size(); i++)
		{
		  if((int)maString[i] >= 65 && (int)maString[i] <= 90 || (int)maString[i] >= 97 && (int)maString[i] <= 122 )
		    {
		      cryptage_tpdes(maString[i], cle);
		      // Stockage dans un autre fichier? 
		    }
		
		}
		   
	    }
	  fichier.close(); 
	}
      else 
	std::cout << "Impossible d'ouvrir le fichier !" << std::endl;
    }
  
  return 0;  
}
