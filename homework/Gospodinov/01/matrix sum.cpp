#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#define MAX 100 // ������������ ������ �����
#define MAX_S 100 // ������������ ������ ������ � ����� 
#define MAX_WORD_COUNT 100 // ������������ �-�� ���� ������� � ��-�

// ������� ��������� �������� �� ������ ������ �������� ��������
int is_letter(char s)
{
	if (s >= '�' && s <= '�' || s >= '�' && s <= '�')// ����� �� ������ s ����� ������� � � �. ��� A � �.
		return 1; // ���� ��� ����� - ����� - ���������� 1
	else
		return 0;
}
// str- ������� ������, begin - ������ � ���������� ���������� ��������
// str_size ������. word- ��� �����, ������� �� ���� � ������ str
// word_size - ��� ������
int match(char* str, int begin, int str_size, char* word, int word_size)
{
	if (begin > 0 && (is_letter(str[begin - 1]) || str[begin - 1] == '-')) // ���� ���������� ������ ������ �������� ������, ������, �� ����� ������ ����� (������: ���� "��" � ������ "�����")
		return 0;
	else if (str_size - begin < word_size)// ���� ������� ������ ������ �����, �� �� ����� �����, � ������ 0
		return 0;
	else
	{
		for (int i = 0; i < word_size; i++)// ��������� � ����� ������ ����� 
		{
			if (str[i + begin] != word[i])// �������� ����, ����� �� ������� ������ ����� �������� ������� ������  
				return 0;// ���� ��� �� �����, �� �� ����� ����� ����� ����� � ���������� 0
		}
		if (word_size + begin < str_size && (is_letter(str[word_size + begin]) || str[word_size + begin] == '-')) // ���� ��� ������� ����� ��������� � ��������� ������, �� ����� ���� �������� � ������ ���� �����, ������ �� ����� ����� ������� �����, � �� ��������������� ����� (������: ���� "��" � ������ "�����")
			return 0;
		return 1;// ���� ��� ������� ��������� ���������� 1
	}
}

// ��������� new-str(������������ ������, �� ������� �� ������� �����).
// str-��������� ������. str_size - ������ ������. word-����� ������� �������
// word_size - ������ ���������� �����
void delete_words(char* new_str, char* str, int str_size, char* word, int word_size)
{
	int j = 0;
	for (int i = 0; i < str_size; i++)// ���� ������������ ��������� ������� ������
	{
		if (!is_letter(str[j])) //���� ������ �� �����, �� :
		{
			new_str[j] = str[i]; // �� ��� �������� � ����� ������ 
			j++;// �������� ������(������ ����� ������ �������)
			continue;// ���� ���������� � 37 ������ 
		}
		else // ���� ������ �������� ������ 
		{
			if (match(str, i, str_size, word, word_size))// ���������� ������� match. ���� ����� word � ������ str, ������� � ������� str[i].
			{// ���� ����� 
				i += word_size - 1;// �� ��������  ������, ����� �� ���������� ����� 
			}
			else
			{
				new_str[j] = str[i];// ����� ������ �������� ������� ������
				j++; // �������� �� ���������� ������� 
			}
		}
	}
	new_str[j] = '\0'; // � ����� ��������� ������ ����� ������ 
}

int main(void)
{
	SetConsoleCP(1251); // �������
	SetConsoleOutputCP(1251); // �������� 

	char word[MAX][MAX_WORD_COUNT];// ������ ����, ������� ����� ������� 
	int size; // ������ ������� ����
	printf("/* ��� ��������� ����� ���� ������� <enter> */\n");
	for (size = 0; size < MAX_WORD_COUNT; size++)// ��������� ����� ������� 
	{
		printf("������� �����: ");
		gets_s(word[size]);// ����������� ���������� ���� 
		if (strlen(word[size]) == 0)// ���� �� ������� ������ ������, �� ��������� ���������� 
			break; // �������� ��������� ����� 
	}
	printf("������� %d ����\n", size); // ������� ������� ����� ���� �������

	FILE* input = fopen("input.txt", "r");// ��������� ���� input.txt �� ������
	FILE* output = fopen("output.txt", "w");// ��������� ���� output.txt �� ������
	char str[MAX_S]; // ����� ��� ������ 
	while (fgets(str, MAX_S, input) != NULL) // ��������� ������ �� �����  � ��������� �� ������ �� ���. ���� ��� ������ - ��������� end. � ���� �� ������ ��: 
	{
		for (int i = 0; i < size; i++) //� ����� ������� ����� �� ��������� ������ 
			delete_words(str, str, strlen(str), word[i], strlen(word[i]));
		fprintf(output, "%s", str);// ������� ��� ������ � ����� ���� 
	}
	fclose(input); // ��������� ����� 
	fclose(output);

	return 0;
}