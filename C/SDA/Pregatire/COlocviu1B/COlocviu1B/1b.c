#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
	int key;
	int status;
} Cell;

enum { FREE, OCCUPIED };

void afisare(Cell* T, int m)
{
	printf("\n\nTabela de dispersie este \n");
	for (int i = 0; i < m; i++)
	{
		if (T[i].status == OCCUPIED)
			printf("T[%d]=%d\n", i, T[i]);
		else
			printf("T[%d]= --\n", i);
	}
}

void insert_key(int k, Cell * T, int m, int (*hash_func)(int k, int m, int i))
{
	int i;
	for (i = 0; i < m; i++) {
		int h = hash_func(k, m, i);
		if (T[h].status == FREE) {
			T[h].status = OCCUPIED;
			T[h].key = k;
			return;
		}

	}
	printf("Nu putem insera elementul %d!\n", k);
}


int h_prime(int k, int m)
{
	return (k*k) % m;
}

int h_second(int k, int m)
{
	return 5 - (k % 5);
}

//returneaza pozitia la care se va verifica tabela de dispersie folosind verificarea liniara

//h(k;i) = (h0(k) + i) mod m
int linear_probing(int k, int m, int i)
{
	return (h_prime(k, m) + i) % m;
}


//h(k, i) = (h0(k)+c1 × i + c2 × i2) mod m unde c1 = 1, c2 = 1
int quadratic_probing(int k, int m, int i)
{
	return (h_prime(k, m) + i + i * i) % m;
}


//h(k, i) = (h1(k) + i × h2(k)) mod m
int double_hashing(int k, int m, int i)
{
	return (h_prime(k, m) + i * h_second(k, m)) % m;
}

void set_table_free(Cell * T, int m)
{
	//initializam tabela
	int i;
	for (i = 0; i < m; i++)
	{
		T[i].status = FREE;
	}
}

int main()
{
	int m = 8;
	Cell* T = (Cell*)malloc(m * sizeof(Cell)); //tabela de dispersie - se aloca

	//test linear probing
	set_table_free(T, m);
	int vals[] = { 8, 10, 5, 8, 6, 9 };
	for (int i = 0; i < sizeof(vals) / sizeof(int); i++)
		insert_key(vals[i], T, m, linear_probing);
	afisare(T, m);
	//21, 36, 26, 14, 4, 19, 5

	return 0;
}
