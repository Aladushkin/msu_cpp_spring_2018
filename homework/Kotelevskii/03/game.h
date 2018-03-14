#pragma once
#include<iostream>
#include <string>

// ����� ������������ ��������
class animate
{
protected:
	int health; //� ������� ���� �����-�� ��������, ���� ��� <= �� �������� ��������
	void set_health(int q);
	std::string personal_name; 
	void set_personal_name(std::string N_name);
	int damage_without_weapon; //���� �������� ��� ������ ( � ����� ��� �������� ����� ���� ���� �� ������ )
	void set_damage_without_weapon(int d);
public:
	animate();
	~animate();
};

// ����� �������������� ��������
class inanimate
{
protected:
	int weigth; //��� ��������, ������� �� ����� �������� � ������� � ��������
	int condition; //100- ��������� ���������, 0 - ������
	void set_weigth(int q);
	void change_condition();//����� ������������� �������� ��� �������� ����� ��������
public:
	inanimate();
	~inanimate();
};

// ����� �����
class human: public animate
{
protected:
	bool gender; //0-�������, 1-�������
	int age; //������� ����� ��������
	int full_damage; // ������ ����, ����������� ���� ������ � ���� ��������
	void set_full_damage(int d);
	void set_gender(bool g);
	void set_age(int a);
public:
	human();
	~human();
};

//����� ��������
class animal : public animate
{
public:
	animal();
	~animal();
};

//����� ������
class pig : public animal
{
public:
	pig();
	~pig();
};


//����� ������
class weapon : public inanimate
{
protected:
	int weapon_damage; //���� ������
	void set_weapon_damage(int d);
public:
	weapon();
	~weapon();
};

//����� �������
class knight : public human
{
public:
	knight();
	sword* Sword;
	lats* Lats;
	~knight();
};
//����� ��������
class archer : public human
{
public:
	archer();
	bow* Bow;
	hauberk* Hauberk;
	~archer();
};
//����� ��������
class peasant : public human
{
public:
	peasant();
	shovel* Shovel;
	~peasant();
};

//����� �����
class sword :public weapon
{
public:
	sword();
	~sword();
};
//����� �����
class bow :public weapon
{
public:
	bow();
	~bow();
};
//����� �����
class shovel :public weapon
{
public:
	shovel();
	~shovel();
};

class armor : public inanimate
{
protected:
	int protection;
	void set_protection(int p);
public:
	armor();
	~armor();
};

//����
class lats : public armor
{
public:
	lats();
	~lats();
};

//��������
class hauberk : public armor
{
public:
	hauberk();
	~hauberk();
};

