#include <stdio.h>

#define MAX 100

int main()
{
	int n,m,ss=1,p=1;		//n�� �Ѻ����� , m  ����

	int arr[MAX][MAX];
	
	scanf("%d %d", &n ,&m);


	if (m == 1)
	{
		for (int i = 0; i < n; i++)					//���� 1��
		{
			for (int k = 0; k < n; k++)
			{
				arr[i][k] = i + 1;
			}
		}

		for (int i = 0; i < n; i++)					//���� 1��
		{
			for (int k = 0; k < n; k++)
			{
				printf("%d ", arr[i][k]);
			}
			printf("\n");
		}


		
	}

	if (m == 2)
	{

		for (int i = 0, ss = 1; i < n; i++)							// ���� 2��
		{
			if (i % 2 == 0)
			{
				for (int k = 0; k < n; k++)
				{
					arr[i][k] = ss;
					ss++;
				}
			}


			else
			{
				for (int k = n - 1, ss = 1; k >= 0; k--)
				{
					arr[i][k] = ss;
					ss++;
				}

			}
			ss = 1;
		}


		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < n; k++)
			{
				printf("%d ", arr[i][k]);
			}
			printf("\n");
		}

	}

	if (m == 3)
	{

		for (int i = 0; i < n; i++)						//3��
		{
			p = ss;
			for (int k = 0; k < n; k++)
			{
				arr[i][k] = ss;
				ss += p;
			}

			p++;
			ss = 1;
			ss += i + 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < n; k++)
			{
				printf("%d ", arr[i][k]);
			}
			printf("\n");
		}

	}

	return 0;
}