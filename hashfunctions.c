#include <stdio.h>
#include <math.h>

//Die in der Vorlesung verwendeten Hashfunktionen. Ich hasse Hasfunktionen
const float A_FACTOR = (pow(5,0.5)-1)/2;/* magic val from lecture*/
const int SIZE_OF_HASH = 100;
int HASH_TABLE[100];

int hash1(int key, int i){/* works for Hashsizes which are prime numbers since gcd(SIZE_OF_HASH,key%(SIZE_OF_HASH-1)+1)) = 1*/
    return (key + i*(key%(SIZE_OF_HASH-1)+1)) % SIZE_OF_HASH ;
}

int hash2(int key, int i){
    return ((int)(SIZE_OF_HASH*(key*A_FACTOR - floor(key*A_FACTOR))) + i) % SIZE_OF_HASH;
}

int hash3(int key, int i){
    return (key + i) % SIZE_OF_HASH ;
}
