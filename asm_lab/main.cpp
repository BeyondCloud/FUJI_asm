
int Input (int x,int y);

int main ()
{
	int a = 30;
	int b = 500;
	Input (a,b);
	return 0;
}


int Input (int x, int y)
{
	int op = 3;
	switch (op)
	{
		case 1:
			return  x + y;
			break;

		case 2:
			return  x - y;
			break;

		case 3:
			return  x * y;
			break;

		case 4:
			return x / y;
			break;
	}

}
