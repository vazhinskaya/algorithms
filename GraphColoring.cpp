#include <iostream>
#define TRUE 1
#define FALSE 0
using namespace std;
typedef int Boolean;
typedef struct Leader *Lref;
typedef struct Trailer *Tref; 

typedef struct Leader
{
	int Key; 
	int Count;
	int Color;
	Boolean Flag;
	Tref Trail; 
	Lref Next; 
};

typedef struct Trailer
{
	Lref Id;
	Tref Next;
};

typedef Lref TipElement; 
typedef struct Zveno *svqz;
typedef struct Zveno
{
	TipElement Element; 
	svqz Sled;
};

class Spisok
{
private:
	Lref Head; 
	Lref Tail; 
	int MSet[256]; 
	void Udalenie_A(svqz *, svqz *, TipElement *);
	void Dobavlenie(svqz *, svqz *, TipElement);
public:
	Spisok() {
		Head = Tail = new (Leader);
	}
	Lref GetHead() { return Head; }
	Lref GetTail() { return Tail; }
	void MakeGraph();
	void PrintGraph();
	void Color(Lref, int);
	void Postr(int);
};

int main()
{
	Spisok A;
	Lref t; 
	int n = 10;

	
	A.MakeGraph();
	A.PrintGraph(); cout << endl;

	t = A.GetHead();
	while (t != A.GetTail())
	{
		t->Flag = TRUE; t->Color = 0;
		n++; t = (*t).Next;
	}

	A.Postr(n);
	cout << "–езультат: ";
	A.Color(A.GetHead(), n);
	cout << endl;
}

void Spisok::Postr(int n)
{
	for (int i = 0;i < 256;i++)
		MSet[i] = (i <= n) ? 1 : 0;
}

void Spisok::MakeGraph()
{
	int x, y;
	Lref p, q; 
	Tref t, r; 
	Boolean Res; 
	cout << "¬водите начальную вершину: ";
	cin >> x;
	while (x != 0)
	{
		cout << "¬водите конечную вершину: "; cin >> y;
		*p = Head; (*Tail).Key = x;
		while ((**p).Key != x) *p = (**p).Next;
		if (*p == Tail)
		{
			Tail = new (Leader); (**p).Count = 0;
			(**p).Trail = NULL; (**p).Next = Tail;
			r = (*p).Trail;
			t = new (Trailer); (*t).Id = q;
			(*t).Next = (*p).Trail; (*p).Trail = t; (*q).Count++;
		}
	}
}

void Spisok::PrintGraph() {
	Lref p;
	Tref q;

	p = Head;
	while (p != Tail)
	{
		cout << (*p).Key ; q = (*p).Trail;
		while (q != NULL)
		{
			cout << (*(*q).Id).Key; q = (*q).Next;
		}
		p = (*p).Next; cout << " ";
	}
}

void Spisok::Dobavlenie(svqz *L, svqz *R, TipElement elem) {
	svqz K = new (Zveno);

	K->Element = elem; K->Sled = NULL;
	if (*L == NULL)
	{
		(*L) = K; (*R) = K;
	}
	else { (*R)->Sled = K; (*R) = K; }
}

void Spisok::Udalenie_A(svqz *L, svqz *R, TipElement *A) {
	svqz q;

	if ((*L) != NULL)
		if ((*L)->Sled != NULL)
		{
			(*A) = (*L)->Element; q = (*L);
			(*L) = (*L)->Sled; delete q;
		}
		else {
			(*A) = (*L)->Element; delete *L;
			(*L) = (*R) = NULL;
		}
}

void Spisok::Color(Lref H, int n) {
	svqz L;   
	svqz R;   
	Lref p;   
	Tref t;   
	Tref t1;
	int i;    
	Boolean Fl;

	L = R = NULL; 
	Dobavlenie(&L, &R, H); H->Flag = FALSE;
	while (L != NULL) {
		Udalenie_A(&L, &R, &p);
		t = p->Trail;
		t1 = t;
		while (t1 != NULL)
		{
			MSet[t1->Id->Color] = 0; t1 = t1->Next;
		}
		Fl = TRUE; i = 1;
		while (Fl)
			if (MSet[i]) Fl = FALSE; else  i++;
		p->Color = i;   
		cout << "(" << p->Key << "," << p->Color << ") ";
		for (i = 0;i < 256;MSet[i++] = 0);
		for (i = 0;i <= n;MSet[i++] = 1);
		while (t != NULL)
		{
			if (t->Id->Flag)
			{
				Dobavlenie(&L, &R, t->Id);
				t->Id->Flag = FALSE;
			}
			t = t->Next;
		}
	}
}

