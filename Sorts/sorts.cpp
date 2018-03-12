/*
���������㷨�� ���Ը����㷨��ʱ��Ч�����˲���
���������㷨���鲢���򡢿�������ð�����򡢲�������ѡ������
2018-3-12�� pengzhyong
*/
#include <time.h>
#include <iostream>
using namespace std;

void genRandomArr(int a[], int len);
int partion(int* data, int start, int len);
void fastSort(int* data, int start, int len);
void mergeArr(int a[], int na, int b[], int nb, int c[]);
void mergeSort(int a[], int start, int end, int tmp[]);
void bubSort(int a[], int len);
void insertSort(int a[], int len);
void choiceSort(int a[], int len);
int main()
{
	clock_t start;
	int a[10000] = { 0 };

	genRandomArr(a, 10000);
	int tmp[10000];
	start = clock();
	mergeSort(a, 0, 9999, tmp);//�鲢
	cout << "merge sort cost " << clock() - start << " ms" << endl;

	genRandomArr(a, 10000);
	start = clock();
	fastSort(a, 0, 9999);//����
	cout << "fast sort cost " << clock() - start << " ms" << endl;


	genRandomArr(a, 10000);
	start = clock();
	bubSort(a, 10000);//ð��
	cout << "bubbling sort cost " << clock() - start << " ms" << endl;

	genRandomArr(a, 10000);
	start = clock();
	insertSort(a, 10000);//����
	cout << "insert sort cost " << clock() - start << " ms" << endl;

	genRandomArr(a, 10000);
	start = clock();
	choiceSort(a, 10000);//ѡ��
	cout << "choice sort cost " << clock() - start << " ms" << endl;

	//����������
	int arr[10] = { 1,4,3,56,2,1,0,-2,3,8 };
	choiceSort(arr, 10);
	for (int i : arr)
		cout << i << ends;
	cout << endl;
	system("pause");
	return 0;
}

void genRandomArr(int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		a[i] = rand() % 1000;
	}
}

int partion(int* data, int start, int end)
{
	if (data == 0 || start < 0 || end <= 0)
	{
		cout << "Invalid input in partion" << endl;
		return -1;
	}
	int pos = start + rand() % (end - start);
	//swap(data[pos], data[end]);
	int ex_pos = start;
	int cur_pos = start;
	while (cur_pos < end)
	{
		if (data[cur_pos] < data[end])
		{
			swap(data[cur_pos], data[ex_pos]);
			ex_pos++;
		}
		cur_pos++;
	}
	swap(data[end], data[ex_pos]);
	return ex_pos;
}

//�����ѵ����ڱ߽�������Ҫ�������п��ܵ����
void fastSort(int* data, int start, int end)
{
	if (data == 0 || end < 0 || start < 0 || end < start)
	{
		cout << "Invalid input" << endl;
		return;
	}
	if ((end - start) < 1)
		return;
	int mid = partion(data, start, end);

	if (mid > start)
		fastSort(data, start, mid - 1);
	if (mid < end)
		fastSort(data, mid + 1, end);
}

void mergeArr(int a[], int na, int b[], int nb, int c[])
{
	int i, j, k;
	i = j = k = 0;
	while (i < na && j < nb)
	{
		if (a[i] > b[j])
			c[k++] = b[j++];
		else
			c[k++] = a[i++];
	}
	while (i < na)
		c[k++] = a[i++];
	while (j < nb)
		c[k++] = b[j++];
}

//�鲢�����ٶȿ죬�ȶ�
void mergeSort(int a[], int start, int end, int tmp[])
{
	if (a == 0 || start < 0 || end < start)
		cout << "Invalid parameters is mergeSort" << endl;
	if (end == start)
		return;
	int mid = start + (end - start) / 2;

	mergeSort(a, start, mid, tmp);
	mergeSort(a, mid + 1, end, tmp);
	mergeArr(a + start, mid - start + 1, a + mid + 1, end - mid, tmp);
	for (int i = start; i < start + (end - start + 1); i++)
		a[i] = tmp[i - start];
	//delete [] cc;
}

//ð������Ч����ͣ��������
void bubSort(int a[], int len)
{
	for (int i = 1; i < len; i++)
	{
		int j = i;
		while (j != 0 && a[j] < a[j - 1])
		{
			swap(a[j], a[j - 1]);
			j--;
		}
	}
}

//��������
void insertSort(int a[], int len)
{
	for (int i = 1; i < len; i++)
	{
		int j = i;
		int insert_pos = 0;
		int insert_value = a[i];
		while (insert_pos != i)
		{
			if (a[insert_pos++] <= a[i])
			{
				continue;
			}
			insert_pos--;
			while (j > insert_pos)
			{
				a[j] = a[j - 1];
				j--;
			}
			a[insert_pos] = insert_value;
			break;
		}
	}
}

//ѡ������
void choiceSort(int a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int min_pos = i;
		for (int j = i; j < len; j++)
		{
			if (a[j] < a[min_pos])
				min_pos = j;
		}
		swap(a[i], a[min_pos]);
	}
}