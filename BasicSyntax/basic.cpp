#include<stdio.h>	//scanf, printf, dkk
#include<stdlib.h>	//rand, malloc, bsearch, qsort
#include<string.h>	//strcpy, strcmp, strstr, strtok, memset
#include<time.h>	//time
#include<math.h>	//sin, cos, tan (dalam radian), M_PI (konstanta pi), sqrt
					//log, log10, log2, ceil, floor, round
#include<queue>		//queue & priority_queue
#include<stack>		//stack
#include<vector>	//vector
#include <map>		//map (sorted, RBTree)
#include <unordered_map>	//unordered_map (unsorted, Hash table)
#include <set>		//set
#include <bitset>	//bitset
#include<functional>	//less & greater
#include<algorithm>		//sort

using namespace std;

class Titik{
	public:
	int x,y;

	Titik(int x, int _y){	//constructor dgn 2 parameter
		this->x = x;				//pakai this-> kalau nama variable dan atribut ambigu
		y = _y;				//boleh tidak pakai this-> kalau tidak ambigu
	}

	Titik(){				//constructor kosong
	}

	//operator overloading <
	bool operator<(const Titik &other) const{
		if(x == other.x)
			return (y < other.y);
		else
			return (x < other.x);
	}
	//const di parameter artinya: parameter itu tidak mungkin berganti nilai
	//const di akhir deklarasi method artinya: method itu tidak mungkin mengubah nilai atribut objek tersebut

	//operator overloading >
	bool operator>(const Titik &other) const{
			if(x == other.x)
				return (y > other.y);
			else
				return (x > other.x);
	}
};

//function untuk membandingkan pointer to object Titik
bool compare(const Titik *a, const Titik *b){
	return *a < *b;
}

int main(){
	priority_queue<Titik> PQ;	//default menggunakan operator <
	priority_queue<Titik, vector<Titik>, greater<Titik> > PQasc;
	queue<Titik> Q;
	stack<Titik> S;
	Titik A(5,5);	//membuat objek, memanggil constructor dengan 2 parameter
	int i;

	srand(time(NULL));		//random dengan seed waktu saat ini
	for(i=0; i<10; i++){
		A.x = rand()%20;	A.y = rand()%20;
		PQ.push(A);			//memasukkan "copy" dari object A ke dalam PQ
		PQasc.push(A);
		Q.push(A);
		S.push(A);
	}

	printf("\nPQ\tPQasc\tQueue\tStack\n");
	while(!Q.empty()){
		printf("(%d,%d)\t", PQ.top().x, PQ.top().y);		PQ.pop();
		printf("(%d,%d)\t", PQasc.top().x, PQasc.top().y);	PQasc.pop();
		printf("(%d,%d)\t", Q.front().x, Q.front().y);		Q.pop();
		printf("(%d,%d)\n", S.top().x, S.top().y);			S.pop();
	}

	Titik *B[10];					//array of pointer to Titik
	vector<int> C;					//vector c
	vector<pair<int, int> > D;		//vector of pair

	for(i=0; i<10; i++){
		B[i] = new Titik(rand()%20 , rand()%20);	//membuat object dinamis
		C.push_back(rand()%20);			//mengisi vector: push_back()
		D.push_back(make_pair(i,i*i));	//membuat pair: make_pair()
	}

	sort(B, B+5, compare);		//mengurutkan array B dari index 0 s.d. 4 saja
								//menggunakan custom sort function, karena B adalah array of pointer
								//jika B adalah array of object, cukup tulis: sort(B, B+5)
	sort(C.begin(), C.end());	//mengurutkan vector dengan .begin() dan .end()
	sort(D.begin(), D.end());	//by default, pair diurutkan berdasarkan element pertama, kemudian element kedua
								//NOTE: compiler lama hanya mengurutkan berdasarkan element pertama saja

	printf("\nB\tC\tD\n");
	for(i=0; i<10; i++){
		printf("(%d,%d)\t", B[i]->x, B[i]->y);
		printf("%d\t", C[i]);	//akses vector sama seperti array
		printf("<%d,%d>\n", D[i].first, D[i].second);	//akses pair menggunakan .first dan .second
	}

	int *E = new int[10];	//membuat array dinamis dengan "new"
	fill(E,E+5, 1);			//mengisi array E index 0 s.d 4 dengan angka 1
	fill(E+5, E+10, 2);		//mengisi array E index 4 s.d. 10 dengan angka 2
	printf("\nIsi E:\n");
	for(i=0; i<10; i++)
		printf("%d ", E[i]);
	printf("\n");

	return 0;
}
